#include "transport_router.h"

namespace transport_catalogue {

namespace infrastructure {

// --- Class TransportRouter ---

TransportRouter::TransportRouter(const TransportRouterSettings& settings)
  : bus_wait_time_(settings.bus_wait_time),
    bus_velocity_ (settings.bus_velocity)
{}

TransportRouter::TransportRouter(const TransportRouterSettings& settings,
                                 const transport_catalogue::business_logic::
                                     TransportCatalogue& transport_catalogue) {

  bus_wait_time_ = settings.bus_wait_time;
  bus_velocity_ = settings.bus_velocity;
  BuildGraph(transport_catalogue);
}

// build a graph based on available stops
const ext_libs::graph::DirectedWeightedGraph<double>&
    TransportRouter::BuildGraph(
        const business_logic::TransportCatalogue& transport_catalogue) {

  // sorting routes
  const auto& ordered_routes = transport_catalogue.OrderRoutes();
   // sorting stops
  const auto& ordered_stops = transport_catalogue.OrderStops();
  double meters_to_kilometer = 1000.0;
  double min_in_hour = 60.0;

  // reserve size for graph incidence lists
  ext_libs::graph::DirectedWeightedGraph<double> stops_graph(
        ordered_stops.size() * 2);

  // correlating stops with graph vertices
  std::map<std::string, ext_libs::graph::VertexId> stops_names_to_vertexes_ids;

  ext_libs::graph::VertexId vertex_id = 0;

  // for each stop name to stop
  for (const auto& [stop_name, stop_info] : ordered_stops) {
    // assign id
    stops_names_to_vertexes_ids[stop_info->name] = vertex_id;

    // add a waiting graph
    stops_graph.AddEdge({
        // waiting vertex
        vertex_id,
        // departure vertex
        ++vertex_id,
        // weight as time in minutes
        static_cast<double>(bus_wait_time_),
        //span_count
        0,
        // stop name
        stop_info->name });
    // next waiting vertex
    ++vertex_id;
  }

  // filling the field
  stops_names_to_vertexes_ids_ = std::move(stops_names_to_vertexes_ids);

  // for each route name to route
  for (auto it = ordered_routes.begin(); it != ordered_routes.end(); ++it) {
    // route info
    const auto& route = it->second;
    // route stops
    const auto& stops = route->stops;
    // route stops count
    size_t stops_count = stops.size();
    // for each stop of the route
    for (size_t i1 = 0; i1 < stops_count; ++i1) {
      // for each other stop ot the route
      for (size_t i2 = i1 + 1; i2 < stops_count; ++i2) {
      // from
      const transport_catalogue::dom_ents::Stop* stop_from = stops[i1];
      // to
      const transport_catalogue::dom_ents::Stop* stop_to = stops[i2];
      // travel time to stop
      double sum_travel_time = 0.0;
      // reverse travel time from stop
      double inv_sum_travel_time = 0.0;
      // for each other stop ot the route
        for (size_t i3 = i1 + 1; i3 <= i2; ++i3) {
          // measure the time of segments
          sum_travel_time +=
              static_cast<double>(
                    transport_catalogue.GetStopDistance(
                        stops[i3 - 1], stops[i3]));
          // measure the reverse time of segments
          inv_sum_travel_time +=
              static_cast<double>(
                  transport_catalogue.GetStopDistance(
                      stops[i3], stops[i3 - 1]));
        }
        // adding edges to each stop of the route
        stops_graph.AddEdge({
            // from
            stops_names_to_vertexes_ids_.at(stop_from->name) + 1,
            // to
            stops_names_to_vertexes_ids_.at(stop_to->name),
            // travel time in minutes
            static_cast<double>(sum_travel_time) /
                (bus_velocity_ * meters_to_kilometer / min_in_hour),
            // span_count
            i2 - i1,
            // bus number
            route->name });

        // additional edge for circular routes
        if (!route->circular) {
            stops_graph.AddEdge({
                // from
                stops_names_to_vertexes_ids_.at(stop_to  ->name) + 1,
                // to
                stops_names_to_vertexes_ids_.at(stop_from->name),
                // travel time in minutes
                static_cast<double>(inv_sum_travel_time) /
                    (bus_velocity_ * meters_to_kilometer / min_in_hour),
                // span_count
                i2 - i1,
                // bus number
                route->name });
        }
      }
    }
  }

  graph_ = std::move(stops_graph);
  router_ = std::make_unique<ext_libs::graph::Router<double>>(graph_);

  return graph_;
}

// building optimal route
const std::optional<ext_libs::graph::Router<double>::RouteInfo>
    TransportRouter::BuildRoute(std::string_view stop_from,
                                std::string_view stop_to) const {
  // building optimal route
  return router_->BuildRoute(
      stops_names_to_vertexes_ids_.at(std::string(stop_from)),
      stops_names_to_vertexes_ids_.at(std::string(stop_to)));
}

const ext_libs::graph::DirectedWeightedGraph<double>&
    TransportRouter::GetGraph() const { return graph_; }

const int TransportRouter::GetWaitTime() const { return bus_wait_time_; }

const double TransportRouter::GetVelocity() const { return bus_velocity_; }

const TransportRouter TransportRouter::GetRouterSettings() const {
  TransportRouter::TransportRouterSettings settings{this->bus_wait_time_,
                                                    this->bus_velocity_};
  return TransportRouter(settings);
};

const std::map<std::string, ext_libs::graph::VertexId>
    TransportRouter::GetStopNameToIds() const {
  return stops_names_to_vertexes_ids_;
}

void TransportRouter::SetGraph(
    const ext_libs::graph::DirectedWeightedGraph<double> graph,
    const std::map<std::string, ext_libs::graph::VertexId> stop_ids) {
  stops_names_to_vertexes_ids_ = stop_ids;
  graph_ = graph;
  // Making sure that the graph referenced by the router
  // does not change its address in memory
  router_ = std::make_unique<ext_libs::graph::Router<double>>(graph_);
}

} // namespace infrastructure - end
} // namespace transport_catalogue - end
