#pragma once

#include "json.h"
#include "transport_catalogue.h"
#include "request_handler.h"
#include "transport_router.h"
#include "map_renderer.h"
#include "domain.h"
#include "json_builder.h"
#include "graph.h"

#include <iostream>
#include <sstream>

// reading json input functions - declaration

namespace transport_catalogue {

namespace infrastructure {

using namespace ext_libs::json;

class JsonReader {
  public:

  JsonReader(std::istream& input) : request_(Parse(input)) {}

  const Node& ProcessBaseRequests() const;

  const Node& ProcessStatRequests() const;

  const Node& ProcessOutputSettings() const;

  const Node& ProcessRoutingSettings() const;

  const Node& ProcessSerializationSettings() const;

  void ProcessInputCatalogueData(
      business_logic::TransportCatalogue& transport_catalogue);

  void ProcessStatRequestToOutput(const Node& stat_requests,
                                  RequestHandler& request_handler) const;

  TransportRouter::TransportRouterSettings ProcessInputRoutingSettings(
      const Node& routing_settings) const;

  MapOutputOperator ProcessInputOutputData(
      const Dict& output_settings_as_map) const;

  const Node OutputStop(const Dict& request_map,
                        RequestHandler& request_handler) const;

  const Node OutputRoute(const Dict& request_map,
                         RequestHandler& request_handler) const;

  const Node OutputMap(const Dict& request_map,
                       RequestHandler& request_handler) const;

  const Node OutputRouteSequence (const Dict& request_map,
                                  RequestHandler& request_handler) const;

  private:

  ext_libs::json::Document request_;
  Node null_node_ = nullptr;

  std::tuple<
      std::string_view,
      dom_ents::geo::Coordinates,
      std::map<std::string_view,
      int>> ProcessInputStop(
          const Dict& stop_as_map) const;

  std::tuple<
      std::string_view,
      std::vector<const dom_ents::Stop*>,
      bool> ProcessInputRoute(
          const Dict& route_as_map,
          business_logic::TransportCatalogue& transport_catalogue) const;

  void ProcessInputStopDistances(
      business_logic::TransportCatalogue& transport_catalogue) const;
};

} // namespace infrastructure - end
} // namespace transport_catalogue - end
