#pragma once

#include "transport_catalogue.h"
#include "graph.h"
#include "router.h"

#include <memory>
#include <optional>


namespace transport_catalogue {

namespace infrastructure {

class TransportRouter {
  public:

  struct TransportRouterSettings {
    // bus waiting time
    int bus_wait_time;
    // bus speed
    double bus_velocity ;
  };

  TransportRouter() = default;

  TransportRouter(const TransportRouterSettings& settings);

  TransportRouter(const TransportRouterSettings& settings,
                  const transport_catalogue::business_logic::
                      TransportCatalogue& transport_catalogue);

  // build a graph based on available stops
  const ext_libs::graph::DirectedWeightedGraph<double>& BuildGraph(
      const business_logic::TransportCatalogue& transport_catalogue);

  // build a route based on existing routes
  const std::optional<ext_libs::graph::Router<double>::RouteInfo> BuildRoute(
      std::string_view stop_from, std::string_view stop_to) const;

  // graph Getter
  const ext_libs::graph::DirectedWeightedGraph<double>& GetGraph() const;

  const int GetWaitTime() const;

  const double GetVelocity() const;

  const TransportRouter GetRouterSettings() const;

  const std::map<std::string,
                 ext_libs::graph::VertexId> GetStopNameToIds() const;

  void SetGraph(
      const ext_libs::graph::DirectedWeightedGraph<double> graph,
      const std::map<std::string, ext_libs::graph::VertexId> stop_ids);

  private:

  // bus waiting time
  int bus_wait_time_ = 0;

  // bus speed
  double bus_velocity_ = 0.0;

  // correlating stops with graph vertices
  std::map<std::string, ext_libs::graph::VertexId> stops_names_to_vertexes_ids_;

  // directed weighted graph from external library
  ext_libs::graph::DirectedWeightedGraph<double> graph_;

  // Make sure that the graph referenced by the router
  // does not change its address in memory.
  // router class from external library, double means edge weight
  std::unique_ptr<ext_libs::graph::Router<double>> router_;
};

} // namespace infrastructure - end
} // namespace transport_catalogue - end
