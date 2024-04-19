#pragma once

#include "svg.h"
#include "geo.h"

#include <string>
#include <vector>
#include <set>

// common domain structures - imlementation
// common domain fuctions - declaration

namespace transport_catalogue {

    namespace dom_ents {

        struct Stop {
            std::string name;
            geo::Coordinates coordinates;
            std::set <std::string> routes_through;
        };

        struct Route {
            std::string name;
            std::vector <const Stop *> stops;
            bool circular;
        };

        struct RouteStats {
            size_t stops_count;
            size_t unique_stops_count;
            double actual_length;
            double curvature;
        };

        struct OutputSettings {
            double width       = 0.0;
            double height      = 0.0;
            double padding     = 0.0;
            double line_width  = 0.0;
            double stop_radius = 0.0;

            int bus_label_font_size  = 0;
            ext_libs::svg::Point bus_label_offset = {0.0, 0.0};

            int stop_label_font_size = 0;
            ext_libs::svg::Point stop_label_offset = {0.0, 0.0};

            ext_libs::svg::Color underlayer_color = {ext_libs::svg::NoneColor};
            double underlayer_width = 0.0;

            std::vector <ext_libs::svg::Color> color_palette {};
        };
    } // namespace dom_ents - end
} // namespace transport_catalogue - end