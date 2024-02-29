#include "map_renderer.h"

// map output functions - implementation

namespace transport_catalogue {

	namespace infrastructure {

		bool IsZero(double value) {
			return std::abs(value) < EPSILON;
		}

		ext_libs::svg::Document MapOutputOperator::MakeDocument(const std::map<std::string_view, const dom_ents::Route*>& routes) const {

			ext_libs::svg::Document doc_result;
			std::vector<dom_ents::geo::Coordinates> coordinates;
			std::map<std::string_view, const dom_ents::Stop*> stops;

			for (const auto& [name, route] : routes) {

				for (const auto& stop : route->stops) {
					coordinates.push_back(stop->coordinates);
					stops[stop->name] = stop;
				}

			}
			SphereProjector sphere_projector (
				coordinates.begin(),
				coordinates.end(),
				output_settings_.width,
				output_settings_.height,
				output_settings_.padding
			);

			for (const auto& line   : MakeWholeRoute (routes, sphere_projector)) {doc_result.Add(line)  ;}
			for (const auto& text   : MakeRouteLabel (routes, sphere_projector)) {doc_result.Add(text)  ;}
			for (const auto& circle : MakeStopSigns  (stops,  sphere_projector)) {doc_result.Add(circle);}
			for (const auto& text   : MakeStopLabel  (stops,  sphere_projector)) {doc_result.Add(text)  ;}
			return doc_result;
		}

		std::vector<ext_libs::svg::Polyline> MapOutputOperator::MakeWholeRoute(const std::map<std::string_view, const dom_ents::Route*>& routes,const SphereProjector& sphere_projector) const {
			std::vector<ext_libs::svg::Polyline> result;
			size_t color_number = 0;

			for (const auto& [name, route] : routes) {
				if (route->stops.empty()) continue;
				std::vector<const dom_ents::Stop*> stops {route->stops.begin(), route->stops.end()};
				if (!route->circular) stops.insert(stops.end(), std::next(route->stops.rbegin()), route->stops.rend());
				ext_libs::svg::Polyline segment;
				for (const auto& stop : stops) {segment.AddPoint(sphere_projector(stop->coordinates));}

				segment.SetStrokeColor    (output_settings_.color_palette[color_number]);
				segment.SetFillColor      ("none");
				segment.SetStrokeWidth    (output_settings_.line_width);
				segment.SetStrokeLineCap  (ext_libs::svg::StrokeLineCap::ROUND);
				segment.SetStrokeLineJoin (ext_libs::svg::StrokeLineJoin::ROUND);

				(color_number < (output_settings_.color_palette.size() - 1)) ? ++color_number : color_number = 0;
				result.push_back(segment);
			}
			return result;
		}

		std::vector<ext_libs::svg::Text> MapOutputOperator::MakeRouteLabel(const std::map<std::string_view, const dom_ents::Route*>& routes_map,const SphereProjector& sphere_projector) const {
			std::vector<ext_libs::svg::Text> result;
			size_t color_number = 0;

			for (const auto& [name, route] : routes_map) {
				if (route->stops.empty()) continue;

				ext_libs::svg::Text underlayer;
				ext_libs::svg::Text text;

				underlayer.SetPosition       (sphere_projector(route->stops[0]->coordinates));
				underlayer.SetOffset         (output_settings_.bus_label_offset);
				underlayer.SetFontSize       (output_settings_.bus_label_font_size);
				underlayer.SetFontFamily     ("Verdana");
				underlayer.SetFontWeight     ("bold");
				underlayer.SetData           (route->name);
				underlayer.SetFillColor      (output_settings_.underlayer_color);
				underlayer.SetStrokeColor    (output_settings_.underlayer_color);
				underlayer.SetStrokeWidth    (output_settings_.underlayer_width);
				underlayer.SetStrokeLineCap  (ext_libs::svg::StrokeLineCap::ROUND);
				underlayer.SetStrokeLineJoin (ext_libs::svg::StrokeLineJoin::ROUND);

				text.SetPosition   (sphere_projector(route->stops[0]->coordinates));
				text.SetOffset     (output_settings_.bus_label_offset);
				text.SetFontSize   (output_settings_.bus_label_font_size);
				text.SetFontFamily ("Verdana");
				text.SetFontWeight ("bold");
				text.SetData       (route->name);
				text.SetFillColor  (output_settings_.color_palette[color_number]);

				((color_number < (output_settings_.color_palette.size() - 1))) ? ++color_number : color_number = 0;

				result.push_back(underlayer);
				result.push_back(text);

				if ((!route->circular) && (route->stops[0] != route->stops[route->stops.size() - 1])) {
					ext_libs::svg::Text text_repeat = text;
					ext_libs::svg::Text underlayer_repeat = underlayer;
					text_repeat.SetPosition(sphere_projector(route->stops[route->stops.size() - 1]->coordinates));
					underlayer_repeat.SetPosition(sphere_projector(route->stops[route->stops.size() - 1]->coordinates));
					result.push_back(underlayer_repeat);
					result.push_back(text_repeat);
				}
			}

			return result;
		}

		std::vector<ext_libs::svg::Circle> MapOutputOperator::MakeStopSigns(const std::map<std::string_view, const dom_ents::Stop*>& stops_map, const SphereProjector& sphere_projector) const {
			std::vector<ext_libs::svg::Circle> result;

			for (const auto& [name, stop] : stops_map) {
				ext_libs::svg::Circle stop_sign;
				stop_sign.SetCenter(sphere_projector(stop->coordinates));
				stop_sign.SetRadius(output_settings_.stop_radius);
				stop_sign.SetFillColor("white");
				result.push_back(stop_sign);
			}

			return result;
		}

		std::vector<ext_libs::svg::Text> MapOutputOperator::MakeStopLabel(const std::map<std::string_view, const dom_ents::Stop*>& stops_map, const SphereProjector& sphere_projector) const {
			std::vector<ext_libs::svg::Text> result;
			ext_libs::svg::Text underlayer;
			ext_libs::svg::Text text;

			for (const auto& [name, stop] : stops_map) {

				underlayer.SetPosition       (sphere_projector(stop->coordinates));
				underlayer.SetOffset         (output_settings_.stop_label_offset);
				underlayer.SetFontSize       (output_settings_.stop_label_font_size);
				underlayer.SetFontFamily     ("Verdana");
				underlayer.SetData           (stop->name);
				underlayer.SetFillColor      (output_settings_.underlayer_color);
				underlayer.SetStrokeColor    (output_settings_.underlayer_color);
				underlayer.SetStrokeWidth    (output_settings_.underlayer_width);
				underlayer.SetStrokeLineCap  (ext_libs::svg::StrokeLineCap::ROUND);
				underlayer.SetStrokeLineJoin (ext_libs::svg::StrokeLineJoin::ROUND);

				text.SetPosition   (sphere_projector(stop->coordinates));
				text.SetOffset     (output_settings_.stop_label_offset);
				text.SetFontSize   (output_settings_.stop_label_font_size);
				text.SetFontFamily ("Verdana");
				text.SetData       (stop->name);
				text.SetFillColor  ("black");
				
				result.push_back(underlayer);
				result.push_back(text);
			}

			return result;
		}

		const dom_ents::OutputSettings MapOutputOperator::GetOutputSettings() const { return output_settings_; };

	} // namespace infrastructure - end
} // namespace transport_catalogue - end