#include "transport_router.h"

namespace transport_catalogue {

    namespace infrastructure {

        // --- Class TransportRouter ---

        TransportRouter::TransportRouter(const TransportRouterSettings& settings) 
            : bus_wait_time_(settings.bus_wait_time)
            , bus_velocity_ (settings.bus_velocity )
        {}

        TransportRouter::TransportRouter(const TransportRouterSettings& settings, const transport_catalogue::business_logic::TransportCatalogue& transport_catalogue) {
            bus_wait_time_ = settings.bus_wait_time;
            bus_velocity_ = settings.bus_velocity;
            BuildGraph(transport_catalogue);
        }

        const ext_libs::graph::DirectedWeightedGraph<double>& TransportRouter::BuildGraph(const business_logic::TransportCatalogue& transport_catalogue) { // build a graph based on available stops

            const auto& ordered_routes = transport_catalogue.OrderRoutes(); // sorting routes
            const auto& ordered_stops = transport_catalogue.OrderStops(); // sorting stops
            double meters_to_kilometer = 1000.0;
            double min_in_hour = 60.0;


            ext_libs::graph::DirectedWeightedGraph<double> stops_graph(ordered_stops.size() * 2);   // reserve size for graph incidence lists
            std::map<std::string, ext_libs::graph::VertexId> stops_names_to_vertexes_ids;           // correlating stops with graph vertices
            ext_libs::graph::VertexId vertex_id = 0;

            for (const auto& [stop_name, stop_info] : ordered_stops) {      // for each stop name to stop
                stops_names_to_vertexes_ids[stop_info->name] = vertex_id;   // assign id
                stops_graph.AddEdge(                                        // add a waiting graph
                    {
                        vertex_id,                                          // waiting vertex
                        ++vertex_id,                                        // departure vertex
                        static_cast<double>(bus_wait_time_),                // weight as time in minutes
                        0,                                                  // span_count
                        stop_info->name                                     // stop name
                    }
                );
                ++vertex_id;                                                // next waiting vertex
            }
            stops_names_to_vertexes_ids_ = std::move(stops_names_to_vertexes_ids);  // filling the field

            for (auto it = ordered_routes.begin(); it != ordered_routes.end(); ++it) { // for each route name to route

                const auto& route = it->second;                 // route info
                const auto& stops = route->stops;               // route stops
                size_t      stops_count = stops.size();         // route stops count

                for (size_t i1 = 0; i1 < stops_count; ++i1) {                               // for each stop of the route
                    for (size_t i2 = i1 + 1; i2 < stops_count; ++i2) {                      // for each other stop ot the route
                        const transport_catalogue::dom_ents::Stop* stop_from = stops[i1];   // from
                        const transport_catalogue::dom_ents::Stop* stop_to   = stops[i2];   // to
                        double sum_travel_time = 0.0;                                       // travel time to stop
                        double inv_sum_travel_time = 0.0;                                   // reverse travel time from stop
                        for (size_t i3 = i1 + 1; i3 <= i2; ++i3) {                          // for each other stop ot the route
                            sum_travel_time += static_cast<double>(transport_catalogue.GetStopDistance(stops[i3 - 1], stops[i3]));      // measure the time of segments
                            inv_sum_travel_time += static_cast<double>(transport_catalogue.GetStopDistance(stops[i3], stops[i3 - 1]));  // measure the reverse time of segments
                        }
                        stops_graph.AddEdge(    // adding edges to each stop of the route
                            {
                                stops_names_to_vertexes_ids_.at(stop_from->name) + 1,   // from
                                stops_names_to_vertexes_ids_.at(stop_to  ->name),       // to
                                static_cast<double>(sum_travel_time) / (bus_velocity_ * meters_to_kilometer / min_in_hour), // travel time in minutes
                                i2 - i1,            // span_count
                                route->name         // bus number
                            }
                        );
                        if (!route->circular) {     // additional edge for circular routes
                            stops_graph.AddEdge(
                                {
                                    stops_names_to_vertexes_ids_.at(stop_to  ->name) + 1,   // from
                                    stops_names_to_vertexes_ids_.at(stop_from->name),       // to
                                    static_cast<double>(inv_sum_travel_time) / (bus_velocity_ * meters_to_kilometer / min_in_hour), // travel time in minutes
                                    i2 - i1,        // span_count
                                    route->name     // bus number
                                }
                            );
                        }
                    }
                }
            }

            graph_  = std::move(stops_graph);
            router_ = std::make_unique<ext_libs::graph::Router<double>>(graph_);

            return graph_;
        }

        const std::optional<ext_libs::graph::Router<double>::RouteInfo> TransportRouter::BuildRoute // building optimal route
        (
            std::string_view stop_from,
            std::string_view stop_to
        )   const 
        {
            return router_->BuildRoute  // building optimal route
            (
                stops_names_to_vertexes_ids_.at(std::string(stop_from)),
                stops_names_to_vertexes_ids_.at(std::string(stop_to))
            );
        }

        const ext_libs::graph::DirectedWeightedGraph<double>& TransportRouter::GetGraph() const { return graph_; }

        const int    TransportRouter::GetWaitTime() const { return bus_wait_time_; }

        const double TransportRouter::GetVelocity() const { return bus_velocity_; }

        const TransportRouter TransportRouter::GetRouterSettings() const {
            TransportRouter::TransportRouterSettings settings{ this->bus_wait_time_, this->bus_velocity_ };
            return TransportRouter(settings);
        };

        const std::map<std::string, ext_libs::graph::VertexId> TransportRouter::GetStopNameToIds() const { return stops_names_to_vertexes_ids_; }

        void TransportRouter::SetGraph(const ext_libs::graph::DirectedWeightedGraph<double> graph, const std::map<std::string, ext_libs::graph::VertexId> stop_ids) {
            stops_names_to_vertexes_ids_ = stop_ids;
            graph_ = graph;
            router_ = std::make_unique<ext_libs::graph::Router<double>>(graph_); // Making sure that the graph referenced by the router does not change its address in memory
        }

    } // namespace infrastructure - end
} // namespace transport_catalogue - end