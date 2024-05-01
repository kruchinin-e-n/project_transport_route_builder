#pragma once

#include "ranges.h"

#include <cstdlib>
#include <vector>

namespace ext_libs {

namespace graph {

using VertexId = size_t;
using EdgeId = size_t;

template <typename Weight>
struct Edge {
  VertexId from;
  VertexId to;
  Weight weight;
  size_t span_count;
  std::string stop_or_route_name;
};

template <typename Weight>
class DirectedWeightedGraph {
  private:

  using IncidenceList = std::vector<EdgeId>;
  using IncidentEdgesRange =
  ranges::Range<typename IncidenceList::const_iterator>;

  public:

  DirectedWeightedGraph() = default;

  explicit DirectedWeightedGraph(size_t vertex_count);

  explicit DirectedWeightedGraph(
    std::vector<Edge<Weight>> edges,
    std::vector<std::vector<EdgeId>> incidence_lists
  );

  // Add an edge to the vector of all edges
  EdgeId AddEdge (const Edge<Weight>& edge);

  // Get count of all vertexes from two-dimensional vector of edge Ids
  size_t GetVertexCount() const;

  // Get count of all edges from vector of all edges
  size_t GetEdgeCount() const;

  // Get edge by id from vector of all edges
  const Edge<Weight>& GetEdge(EdgeId edge_id) const;

  // Get vector of edge Ids by vertex from two-dimensional vector
  // containing of edge Ids
  IncidentEdgesRange GetIncidentEdges(VertexId vertex) const;

  private:

  // vector of all edges
  std::vector<Edge<Weight>> edges_;

  // two-dimensional vector of EdgeIds
  std::vector<IncidenceList> incidence_lists_;
};

template <typename Weight>
DirectedWeightedGraph<Weight>::DirectedWeightedGraph(size_t vertex_count)
  : incidence_lists_(vertex_count) {
}

template <typename Weight>
DirectedWeightedGraph<Weight>::DirectedWeightedGraph(
    std::vector<Edge<Weight>> edges,
    std::vector<std::vector<EdgeId>> incidence_lists)
  : edges_(edges), incidence_lists_(incidence_lists) {
}

template <typename Weight>
EdgeId DirectedWeightedGraph<Weight>::AddEdge(const Edge<Weight>& edge) {
  edges_.push_back(edge);
  const EdgeId id = edges_.size() - 1;
  incidence_lists_.at(edge.from).push_back(id);
  return id;
}

template <typename Weight>
size_t DirectedWeightedGraph<Weight>::GetVertexCount() const {
  return incidence_lists_.size();
}

template <typename Weight>
size_t DirectedWeightedGraph<Weight>::GetEdgeCount() const {
  return edges_.size();
}

template <typename Weight>
const Edge<Weight>& DirectedWeightedGraph<Weight>::GetEdge(
    EdgeId edge_id) const {
  return edges_.at(edge_id);
}

template <typename Weight>
typename DirectedWeightedGraph<Weight>
    ::IncidentEdgesRange DirectedWeightedGraph<Weight>
        ::GetIncidentEdges (VertexId vertex) const {

  return ranges::AsRange(incidence_lists_.at(vertex));
}

} // namespace graph
} // namespace ext_libs
