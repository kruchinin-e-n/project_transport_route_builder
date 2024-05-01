#pragma once

#include "domain.h"
#include "transport_catalogue.h"
#include "map_renderer.h"
#include "transport_router.h"
#include "router.h"
#include "graph.h"

#include <sstream>
#include <optional>
#include <unordered_set>

// connecting between input and output dunctions - declaration

namespace transport_catalogue {

namespace infrastructure {

class RequestHandler {
  public:

  RequestHandler(const MapOutputOperator& map_output_operator,
                 business_logic::TransportCatalogue& transport_catalogue,
                 const TransportRouter& transport_router)

    : map_output_operator_ (map_output_operator),
      transport_catalogue_ (transport_catalogue),
      transport_router_ (transport_router)
  {}

  dom_ents::RouteStats GetRouteStats (std::string_view route_name) const;

  const std::set<std::string> GetRoutesByStop(std::string_view stop_name) const;

  ext_libs::svg::Document OutputMap() const;

  const business_logic::TransportCatalogue& GetCatalogue() const;

  const std::optional<ext_libs::graph::Router<double>::RouteInfo> BuildRoute(
      std::string_view stop_from, std::string_view stop_to) const;

  const ext_libs::graph
      ::DirectedWeightedGraph<double>& GetTransportRouterGraph() const;

  private:
  const infrastructure::MapOutputOperator& map_output_operator_;
  const business_logic::TransportCatalogue& transport_catalogue_;
  const TransportRouter& transport_router_;
};

}  // namespace infrastructure - end
} // namespace transport_catalogue - end
