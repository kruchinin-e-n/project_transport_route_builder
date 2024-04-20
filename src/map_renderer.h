#pragma once

#include "svg.h"
#include "domain.h"

#include <algorithm>
#include <map>

// map output functions - declaration

namespace transport_catalogue {

    namespace infrastructure {

        inline const double EPSILON = 1e-6;
        bool IsZero(double value);

        class SphereProjector {
            public:

            template <typename PointInputIt>
            SphereProjector (
                    PointInputIt points_begin, 
                    PointInputIt points_end,
                    double max_width, 
                    double max_height, 
                    double padding 
                ) : padding_(padding) {

                if (points_begin == points_end) {return;}

                const auto [left_it, right_it] = std::minmax_element(
                    points_begin, 
                    points_end,
                    [] (auto lhs, auto rhs) {return lhs.lng < rhs.lng;}
                );
                min_lon_ = left_it->lng;
                const double max_lon = right_it->lng;

                const auto [bottom_it, top_it] = std::minmax_element(
                    points_begin, 
                    points_end,
                    [] (auto lhs, auto rhs) {return lhs.lat < rhs.lat;}
                );
                const double min_lat = bottom_it->lat;
                max_lat_ = top_it->lat;

                std::optional<double> width_zoom;
                if (!IsZero(max_lon - min_lon_)) {width_zoom = (max_width - 2 * padding) / (max_lon - min_lon_);}

                std::optional<double> height_zoom;
                if (!IsZero(max_lat_ - min_lat)) {height_zoom = (max_height - 2 * padding) / (max_lat_ - min_lat);}

                if (width_zoom && height_zoom) {zoom_coeff_ = std::min(*width_zoom, *height_zoom);}
                else if (width_zoom)  {zoom_coeff_ = *width_zoom ;}
                else if (height_zoom) {zoom_coeff_ = *height_zoom;}
            }

            ext_libs::svg::Point operator()(dom_ents::geo::Coordinates coords) const {
                return {
                    (coords.lng - min_lon_) * zoom_coeff_ + padding_,
                    (max_lat_ - coords.lat) * zoom_coeff_ + padding_
                };
            }

            private:
            double padding_;
            double min_lon_ = 0;
            double max_lat_ = 0;
            double zoom_coeff_ = 0;
        };

        class MapOutputOperator {
            public:
            MapOutputOperator() = default;
            MapOutputOperator(const dom_ents::OutputSettings& output_settings) : output_settings_(output_settings) {}

            ext_libs::svg::Document              MakeDocument   (const std::map<std::string_view, const dom_ents::Route*>& routes) const;
            std::vector<ext_libs::svg::Polyline> MakeWholeRoute (const std::map<std::string_view, const dom_ents::Route*>& routes, const SphereProjector& sphere_projector) const;
            std::vector<ext_libs::svg::Text>     MakeRouteLabel (const std::map<std::string_view, const dom_ents::Route*>& routes, const SphereProjector& sphere_projector) const;
            std::vector<ext_libs::svg::Circle>   MakeStopSigns  (const std::map<std::string_view, const dom_ents::Stop*> & stops , const SphereProjector& sphere_projector) const;
            std::vector<ext_libs::svg::Text>     MakeStopLabel  (const std::map<std::string_view, const dom_ents::Stop*> & stops , const SphereProjector& sphere_projector) const;

            const dom_ents::OutputSettings GetOutputSettings() const;

            private:
            const dom_ents::OutputSettings output_settings_;
        };
    } // namespace infrastructure - end
} // namespace transport_catalogue - end