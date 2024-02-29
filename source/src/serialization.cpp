#include "serialization.h"

namespace transport_catalogue {

	namespace infrastructure {

		namespace protobuf {

			// ------------ PACK BASE ------------

			void Serialize(business_logic::TransportCatalogue& transport_catalogue, MapOutputOperator map_output_operator, const TransportRouter& transport_router, std::ostream& output) {
				transport_catalogue_pb::TransportCatalogue transport_catalogue_pb;

				SerializeStops         (transport_catalogue, transport_catalogue_pb);
				SerializeDistances     (transport_catalogue, transport_catalogue_pb);
				SerializeRoutes        (transport_catalogue, transport_catalogue_pb);
				SerializeOutputSettings(map_output_operator, transport_catalogue_pb);
				SerializeRouter        (transport_router,    transport_catalogue_pb);

				transport_catalogue_pb.SerializeToOstream(&output);
			}

			// --- serialize output part ---

			void SerializeOutputSettings(const MapOutputOperator& map_output_operator, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				const auto output_settings = map_output_operator.GetOutputSettings();
				map_pb::OutputSettings output_settings_pb;
				output_settings_pb.set_width(output_settings.width);
				output_settings_pb.set_height(output_settings.height);
				output_settings_pb.set_padding(output_settings.padding);
				output_settings_pb.set_line_width(output_settings.line_width);
				output_settings_pb.set_stop_radius(output_settings.stop_radius);

				output_settings_pb.set_bus_label_font_size(output_settings.bus_label_font_size);
				*output_settings_pb.mutable_bus_label_offset() = SerializePoint(output_settings.bus_label_offset);

				output_settings_pb.set_stop_label_font_size(output_settings.stop_label_font_size);
				*output_settings_pb.mutable_stop_label_offset() = SerializePoint(output_settings.stop_label_offset);

				*output_settings_pb.mutable_underlayer_color() = SerializeColor(output_settings.underlayer_color);
				output_settings_pb.set_underlayer_width(output_settings.underlayer_width);

				for (const auto& color : output_settings.color_palette) { *output_settings_pb.add_color_palette() = SerializeColor(color); }
				*transport_catalogue_pb.mutable_output_settings() = std::move(output_settings_pb);
			}

			map_pb::Point SerializePoint(const ext_libs::svg::Point& point) {
				map_pb::Point point_pb;
				point_pb.set_x(point.x);
				point_pb.set_y(point.y);
				return point_pb;
			}

			map_pb::ColorVar SerializeColor(const ext_libs::svg::Color& color) {
				map_pb::ColorVar color_pb;
				switch (color.index()) {
				case 1: { color_pb.set_color(std::get<1>(color)); break; }
				case 2: { *color_pb.mutable_rgb() = SerializeRGB(std::get<2>(color)); break; }
				case 3: { *color_pb.mutable_rgbo() = SerializeRGBO(std::get<3>(color)); break; }
				}
				return color_pb;
			}

			map_pb::RGB SerializeRGB(const ext_libs::svg::RGB& rgb) {
				map_pb::RGB rgb_pb;
				rgb_pb.set_red(rgb.red);
				rgb_pb.set_blue(rgb.blue);
				rgb_pb.set_green(rgb.green);
				return rgb_pb;
			}

			map_pb::RGBO SerializeRGBO(const ext_libs::svg::RGBO& rgbo) {
				map_pb::RGBO rgbo_pb;
				rgbo_pb.set_red(rgbo.red);
				rgbo_pb.set_blue(rgbo.blue);
				rgbo_pb.set_green(rgbo.green);
				rgbo_pb.set_opacity(rgbo.opacity);
				return rgbo_pb;
			}

			// --- serialize stats ---

			void SerializeStops(const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				const auto all_stops = transport_catalogue.OrderStops();
				for (const auto& stop : all_stops) {
					transport_catalogue_pb::Stop stop_pb;
					stop_pb.set_name(stop.second->name);
					stop_pb.mutable_coordinates()->set_lat(stop.second->coordinates.lat);
					stop_pb.mutable_coordinates()->set_lng(stop.second->coordinates.lng);
					for (const auto& route : stop.second->routes_through) {
						stop_pb.add_routes_through(route);
					}
					*transport_catalogue_pb.add_stops() = std::move(stop_pb);
				}
			}

			void SerializeDistances(const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				for (const auto& [stops_from_to, distance] : transport_catalogue.GetStopDistances()) {
					transport_catalogue_pb::Distanse distances_pb;
					distances_pb.set_from(stops_from_to.first->name);
					distances_pb.set_to(stops_from_to.second->name);
					distances_pb.set_distance(distance);

					*transport_catalogue_pb.add_stop_distances() = std::move(distances_pb);
				}
			}

			void SerializeRoutes(const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				const auto all_routes = transport_catalogue.OrderRoutes();
				for (const auto& route : all_routes) {
					transport_catalogue_pb::Route route_pb;
					route_pb.set_name(route.second->name);
					for (const auto* stop : route.second->stops) {
						*route_pb.mutable_stops()->Add() = stop->name;
					}
					route_pb.set_circular(route.second->circular);
					*transport_catalogue_pb.add_routes() = std::move(route_pb);
				}
			}

			// --- seraialize ext_libs graph ---

			graph_pb::Graph SerializeGraph(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				graph_pb::Graph graph_pb;
				for (int i = 0; i < transport_router.GetGraph().GetEdgeCount(); ++i) {
					const ext_libs::graph::Edge edge = transport_router.GetGraph().GetEdge(i);
					graph_pb::Edge edge_pb;
					edge_pb.set_from(edge.from);
					edge_pb.set_to(edge.to);
					edge_pb.set_weight(edge.weight);
					edge_pb.set_span_count(edge.span_count);
					edge_pb.set_stop_or_route_name(edge.stop_or_route_name);

					*graph_pb.add_edges() = edge_pb;
				}
				for (int i = 0; i < transport_router.GetGraph().GetVertexCount(); ++i) {
					graph_pb::VertexToEdgeIds vertex_pb;
					for (const auto& edge_id : transport_router.GetGraph().GetIncidentEdges(i)) {
						vertex_pb.add_edge_ids(edge_id);
					}
					*graph_pb.add_vertexes() = vertex_pb;
				}
				return graph_pb;
			}

			// --- seraialize router and routing settings  ---

			transport_router_pb::RoutingSettings SerializeRoutingSettings(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				transport_router_pb::RoutingSettings router_settings_pb;
				router_settings_pb.set_wait_time(transport_router.GetWaitTime());
				router_settings_pb.set_velocity(transport_router.GetVelocity());

				return router_settings_pb;
			}

			void SerializeRouter(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				transport_router_pb::TransportRouter transport_router_pb;
				*transport_router_pb.mutable_routing_settings() = SerializeRoutingSettings(transport_router.GetRouterSettings(), transport_catalogue_pb);
				*transport_router_pb.mutable_graph() = SerializeGraph(transport_router, transport_catalogue_pb);
				for (const auto& [name, id] : transport_router.GetStopNameToIds()) {
					transport_router_pb::StopWithId stop_with_id_pb;
					stop_with_id_pb.set_name(name);
					stop_with_id_pb.set_id(id);

					*transport_router_pb.add_stop_with_ids() = stop_with_id_pb;
				}
				*transport_catalogue_pb.mutable_transport_router() = std::move(transport_router_pb);
			}

			// ------------ UNPACK BASE ------------

			std::tuple
			<
				business_logic::TransportCatalogue, 
				MapOutputOperator, 
				TransportRouter, 
				ext_libs::graph::DirectedWeightedGraph<double>, 
				std::map<std::string, ext_libs::graph::VertexId>
			>
				Deserialize(std::istream& input) {
				transport_catalogue_pb::TransportCatalogue transport_catalogue_pb;
				transport_catalogue_pb.ParseFromIstream(&input);

				business_logic::TransportCatalogue transport_catalogue;

				DeserializeStops    (transport_catalogue, transport_catalogue_pb);
				DeserializeDistances(transport_catalogue, transport_catalogue_pb);
				DeserializeRoutes   (transport_catalogue, transport_catalogue_pb);

				transport_catalogue::dom_ents::OutputSettings output_settings;
				MapOutputOperator  map_output_operator = DeserializeOutputSettings(output_settings, transport_catalogue_pb);
				TransportRouter    router{};

				return { 
					std::move(transport_catalogue),
					std::move(map_output_operator),
					std::move(router), 
					DeserializeGraph(transport_catalogue_pb),
					DeserializeStopNameToIds(transport_catalogue_pb)
				};
			}

			// --- deserialize output part ---

			MapOutputOperator DeserializeOutputSettings(dom_ents::OutputSettings& output_settings, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				const map_pb::OutputSettings& output_settings_pb = transport_catalogue_pb.output_settings();
				output_settings.width                = output_settings_pb.width();
				output_settings.height               = output_settings_pb.height();
				output_settings.padding              = output_settings_pb.padding();
				output_settings.line_width           = output_settings_pb.line_width();
				output_settings.stop_radius          = output_settings_pb.stop_radius();
				output_settings.bus_label_font_size  = output_settings_pb.bus_label_font_size();

				output_settings.bus_label_offset     = DeserializePoint(output_settings_pb.bus_label_offset());
				output_settings.stop_label_font_size = output_settings_pb.stop_label_font_size();
				output_settings.stop_label_offset    = DeserializePoint(output_settings_pb.stop_label_offset());
				output_settings.underlayer_color     = DeserializeColor(output_settings_pb.underlayer_color());
				output_settings.underlayer_width     = output_settings_pb.underlayer_width();
				for (int i = 0; i < output_settings_pb.color_palette_size(); ++i) {
					output_settings.color_palette.push_back(DeserializeColor(output_settings_pb.color_palette(i)));
				}
				return output_settings;
			}

			ext_libs::svg::Point DeserializePoint(const map_pb::Point& point_pb) { return { point_pb.x(), point_pb.y() }; }

			ext_libs::svg::Color DeserializeColor(const map_pb::ColorVar& color_pb) {
				if (color_pb.has_rgb()) {
					return ext_libs::svg::RGB{
						static_cast<int>(color_pb.rgb().red()),
						static_cast<int>(color_pb.rgb().green()),
						static_cast<int>(color_pb.rgb().blue())
					};
				}
				else if (color_pb.has_rgbo()) {
					return ext_libs::svg::RGBO{ 
						static_cast<uint8_t>(color_pb.rgbo().red()),
						static_cast<uint8_t>(color_pb.rgbo().green()),
						static_cast<uint8_t>(color_pb.rgbo().blue()),
						color_pb.rgbo().opacity() };
				}
				else return color_pb.color();
			}

			// --- deserizlize stats ---

			void DeserializeStops(business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				for (int i = 0; i < transport_catalogue_pb.stops_size(); ++i) {
					const transport_catalogue_pb::Stop& stop_pb = transport_catalogue_pb.stops(i);
					transport_catalogue.AddStop(stop_pb.name(), { stop_pb.coordinates().lat(), stop_pb.coordinates().lng() });
				}
			}

			void DeserializeDistances(business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				for (size_t i = 0; i < transport_catalogue_pb.stop_distances_size(); ++i) {
					const transport_catalogue_pb::Distanse& stop_distances_pb = transport_catalogue_pb.stop_distances(i);
					const dom_ents::Stop* from = transport_catalogue.FindStop(stop_distances_pb.from());
					const dom_ents::Stop* to = transport_catalogue.FindStop(stop_distances_pb.to());
					transport_catalogue.AddToStopDistances(from, to, stop_distances_pb.distance());
				}
			}

			void DeserializeRoutes(business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				for (size_t i1 = 0; i1 < transport_catalogue_pb.routes_size(); ++i1) {
					const transport_catalogue_pb::Route& route_pb = transport_catalogue_pb.routes(i1);
					std::vector<const dom_ents::Stop*> stops(route_pb.stops_size());
					for (size_t i2 = 0; i2 < stops.size(); ++i2) {
						stops[i2] = transport_catalogue.FindStop(route_pb.stops(i2));
					}
					transport_catalogue.AddRoute(route_pb.name(), stops, route_pb.circular());
				}
			}

			// --- deserialize ext_libs graph ---

			ext_libs::graph::DirectedWeightedGraph<double> DeserializeGraph(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				const graph_pb::Graph& graph_pb = transport_catalogue_pb.transport_router().graph();
				std::vector<ext_libs::graph::Edge<double>> edges(graph_pb.edges_size());
				std::vector<std::vector<ext_libs::graph::EdgeId>> incidence_lists(graph_pb.vertexes_size());
				for (int i = 0; i < graph_pb.edges_size(); ++i) {
					const graph_pb::Edge& edge_pb = graph_pb.edges(i);
					edges[i] = 
					{ 
						static_cast<size_t>(edge_pb.from()),
						static_cast<size_t>(edge_pb.to()),
						edge_pb.weight(),
						static_cast<size_t>(edge_pb.span_count()),
						edge_pb.stop_or_route_name(),
					};
				}
				for (size_t i = 0; i < incidence_lists.size(); ++i) {
					const graph_pb::VertexToEdgeIds& vertex_pb = graph_pb.vertexes(i);
					incidence_lists[i].reserve(vertex_pb.edge_ids_size());
					for (const auto& id : vertex_pb.edge_ids()) { incidence_lists[i].push_back(id); }
				}
				return ext_libs::graph::DirectedWeightedGraph<double>(edges, incidence_lists);
			}

			std::map<std::string, ext_libs::graph::VertexId> DeserializeStopNameToIds(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				std::map<std::string, ext_libs::graph::VertexId> stop_name_to_ids;
				for (const auto& stop_name_to_id_pb : transport_catalogue_pb.transport_router().stop_with_ids()) { 
					stop_name_to_ids[stop_name_to_id_pb.name()] = stop_name_to_id_pb.id(); 
				}
				return stop_name_to_ids;
			}

			// --- deserizlize routing settings ---

			TransportRouter DeserializeRoutingSettings(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb) {
				TransportRouter::TransportRouterSettings settings{
					transport_catalogue_pb.transport_router().routing_settings().wait_time(),
					transport_catalogue_pb.transport_router().routing_settings().velocity()
				};
				return TransportRouter{ settings };
			}

		} // namespace protobuf - end
	} // namespace infrastructure - end
} // namespace transport_catalogue - end