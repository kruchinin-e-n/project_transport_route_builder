#pragma once

#include "graph.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

namespace ext_libs {

namespace graph {

template <typename Weight>
class Router {
  private:

  using Graph = DirectedWeightedGraph<Weight>;

  public:

  explicit Router(const Graph& graph);

  struct RouteInfo {
    Weight weight;
    std::vector<EdgeId> edges;
  };

  std::optional<RouteInfo> BuildRoute(VertexId from, VertexId to) const;

  private:

  struct RouteInternalData {
    Weight weight;
    std::optional<EdgeId> prev_edge;
  };

  using RoutesInternalData =
      std::vector<std::vector<std::optional<RouteInternalData>>>;

  // This function is used to initialize route data for all nodes in the graph.
  void InitializeRoutesInternalData(const Graph& graph) {

    // Get the total count of vertices/nodes in the graph
    const size_t vertex_count = graph.GetVertexCount();

    // Loop through each vertex
    for (VertexId vertex = 0; vertex < vertex_count; ++vertex) {

      // Initialize the weight as ZERO_WEIGHT and edge
      // as std::nullopt for route from a vertex to itself
      routes_internal_data_[vertex][vertex] =
          RouteInternalData{ ZERO_WEIGHT, std::nullopt };

      // Loop through each edge of the current vertex
      for (const EdgeId edge_id : graph.GetIncidentEdges(vertex)) {

        // Grab the detailed information of the edge
        const auto& edge = graph.GetEdge(edge_id);

        // If the weight is less than ZERO_WEIGHT,
        // throw an error because negative weights aren't allowed
        if (edge.weight < ZERO_WEIGHT) {
          throw std::domain_error("Edges' weights should be non-negative");
        }

        // Refer the possible existing route from 'vertex' to 'edge.to'
        auto& route_internal_data = routes_internal_data_[vertex][edge.to];

        // If there's no existing route OR the existing route's weight
        // is greater than the current edge's weight,
        // update the route information with the current edge's weight and ID
        // It keeps the route with the least weight
        if(!route_internal_data
            || route_internal_data->weight > edge.weight) {
          route_internal_data = RouteInternalData{ edge.weight, edge_id };
        }
      }
    }
  }

  // This function is used to optimize, "relax" the route between two vertices.
  void RelaxRoute(VertexId vertex_from,
                  VertexId vertex_to,
                  const RouteInternalData& route_from,
                  const RouteInternalData& route_to) {

    // Get the route between 'vertex_from'
    // and 'vertex_to' from the existing routes data.
    // This is the route that could potentially be 'relaxed' or optimized.
    auto& route_relaxing = routes_internal_data_[vertex_from][vertex_to];

    // Add up the weights of 'route_from' and 'route_to'
    // to come up with a candidate weight for the optimized route.
    const Weight candidate_weight = route_from.weight + route_to.weight;

    // If 'route_relaxing' doesn't already exist
    // (i.e., there's currently no route between
    // 'vertex_from' and 'vertex_to') or if 'candidate_weight'
    // is less than the weight of 'route_relaxing'.
    // This means that we've found a more optimal route between
    // 'vertex_from' and 'vertex_to'.
    if (!route_relaxing || candidate_weight < route_relaxing->weight) {

      // 'Relax' or optimize 'route_relaxing'
      // by setting its weight to 'candidate_weight'
      // and its 'prev_edge' to 'route_to.prev_edge'
      // if it exists, otherwise to 'route_from.prev_edge'.
      // This is done because once 'route_relaxing'
      // is optimized, the more optimal path or route
      // used to reach 'vertex_to' from 'vertex_from'
      // is via 'route_to.prev_edge' if it exists.
      // If it doesn't, the more optimal path is via 'route_from.prev_edge'.
      route_relaxing =
          { candidate_weight,
            route_to.prev_edge ? route_to.prev_edge : route_from.prev_edge}; }
  }

  // This function attempts to optimize all routes
  // in the graph by considering the given vertex as an intermediate vertex.
  void RelaxRoutesInternalDataThroughVertex(size_t vertex_count,
                                            VertexId vertex_through) {
    // Loop through all vertices in the graph
    // to consider each one as the starting point of a route
    for (VertexId vertex_from = 0; vertex_from < vertex_count; ++vertex_from) {
      // Get the route from 'vertex_from' to 'vertex_through'.
      // Only proceed if such a route exists.
      if (const auto& route_from =
          routes_internal_data_[vertex_from][vertex_through]) {
        // For the given 'vertex_from', loop through
        // all other vertices in the graph to
        // consider each one as the ending point of a route
        for (VertexId vertex_to = 0; vertex_to < vertex_count; ++vertex_to) {
          // Get the route from 'vertex_through' to 'vertex_to'.
          // Only proceed if such a route exists.
          if (const auto& route_to =
              routes_internal_data_[vertex_through][vertex_to]) {
            // Attempt to 'relax' or optimize the route
            // from 'vertex_from' to 'vertex_to'
            // by potentially using 'vertex_through' as an intermediate vertex.
            // 'RelaxRoute' will compare the total weight of two paths:
            // 1. The existing direct path from 'vertex_from' to 'vertex_to'
            // 2. The new path that goes from 'vertex_from'
            // to 'vertex_through', then from 'vertex_through' to 'vertex_to'.
            // If the second path has lesser weight,
            // the 'relaxation' process will update the route data
            // for the path from 'vertex_from' to 'vertex_to'.
            RelaxRoute(vertex_from, vertex_to, *route_from, *route_to);
          }
        }
      }
    }
  }

  static constexpr Weight ZERO_WEIGHT{};

  const Graph& graph_;

  RoutesInternalData routes_internal_data_;
};

template <typename Weight>
Router<Weight>::Router(const Graph& graph)
  : graph_(graph)
  , routes_internal_data_(graph.GetVertexCount(),
      std::vector<std::optional<RouteInternalData>>(graph.GetVertexCount())) {
  InitializeRoutesInternalData(graph);

  const size_t vertex_count = graph.GetVertexCount();
  for (VertexId vertex_through = 0; vertex_through < vertex_count;
       ++vertex_through) {
    RelaxRoutesInternalDataThroughVertex(vertex_count, vertex_through);
  }
}

template <typename Weight>
std::optional<typename Router<Weight>
    ::RouteInfo> Router<Weight>
        ::BuildRoute(VertexId from, VertexId to) const {
  const auto& route_internal_data = routes_internal_data_.at(from).at(to);
  if (!route_internal_data) {return std::nullopt;}
  const Weight weight = route_internal_data->weight;
  std::vector<EdgeId> edges;
  for (std::optional<EdgeId> edge_id = route_internal_data->prev_edge;
       edge_id;
       edge_id =
          routes_internal_data_[from][graph_
              .GetEdge(*edge_id).from]->prev_edge) {
    edges.push_back(*edge_id);
  }

  std::reverse(edges.begin(), edges.end());

  return RouteInfo{ weight, std::move(edges) };
}

} // namespace graph - end
}  // namespace ext_libs - end
