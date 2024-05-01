#include "json_reader.h"

// reading json input functions - implementation

namespace transport_catalogue {

namespace infrastructure {

// --- class JsonReader ---

const Node& JsonReader::ProcessBaseRequests() const {
  if (request_.GetRoot().AsMap().count("base_requests") == 0) {
    return null_node_;
  }
  return request_.GetRoot().AsMap().at("base_requests");
}

const Node& JsonReader::ProcessStatRequests() const {
  if (request_.GetRoot().AsMap().count("stat_requests") == 0) {
    return null_node_;
  }
  return request_.GetRoot().AsMap().at("stat_requests");
}

const Node& JsonReader::ProcessOutputSettings() const {
  if (request_.GetRoot().AsMap().count("render_settings") == 0) {
    return null_node_;
  }
  return request_.GetRoot().AsMap().at("render_settings");
}

const Node& JsonReader::ProcessRoutingSettings() const {
  if (request_.GetRoot().AsMap().count("routing_settings") == 0) {
    return null_node_;
  }
  return request_.GetRoot().AsMap().at("routing_settings");
}

const Node& JsonReader::ProcessSerializationSettings() const {
  if (!request_.GetRoot().AsMap().count("serialization_settings")) {
    return null_node_;
  }
  return request_.GetRoot().AsMap().at("serialization_settings");
}

void JsonReader::ProcessInputCatalogueData(
    business_logic::TransportCatalogue& transport_catalogue) {
  const Array& base_requests_as_array = ProcessBaseRequests().AsArray();

  for (auto& stop_or_route : base_requests_as_array) {
    const auto& stop_or_route_as_map = stop_or_route.AsMap();
    const auto& type = stop_or_route_as_map.at("type").AsString();
    if (type == "Stop") {
      auto [name, coordinates, stop_distances] =
          ProcessInputStop(stop_or_route_as_map);
      transport_catalogue.AddStop(name, coordinates);
    }
  }

  ProcessInputStopDistances(transport_catalogue);

  for (auto& stop_or_route : base_requests_as_array) {
    const auto& stop_or_route_as_map = stop_or_route.AsMap();
    const auto& type = stop_or_route_as_map.at("type").AsString();
    if (type == "Bus") {
      auto [name, stops, circular] =
          ProcessInputRoute(stop_or_route_as_map, transport_catalogue);
      transport_catalogue.AddRoute(name, stops, circular);
    }
  }
}

std::tuple<std::string_view, dom_ents::geo::Coordinates,
           std::map<std::string_view,int>>
JsonReader::ProcessInputStop(const ext_libs::json::Dict& stop_as_map) const {
  std::string_view name = stop_as_map.at("name").AsString();
  dom_ents::geo::Coordinates coordinates = {
      stop_as_map.at("latitude").AsDouble(),
      stop_as_map.at("longitude").AsDouble() };

  std::map<std::string_view, int> stop_distances;
  auto& distances = stop_as_map.at("road_distances").AsMap();

  for (auto& [name, distance] : distances) {
    stop_distances.emplace(name, distance.AsInt());
  }
  return std::make_tuple(name, coordinates, stop_distances);
}

void JsonReader::ProcessInputStopDistances(
    business_logic::TransportCatalogue& transport_catalogue) const {
  const Array& base_request_as_array = ProcessBaseRequests().AsArray();

  for (auto& stop_or_route : base_request_as_array) {
    const auto& stop_or_route_as_map = stop_or_route.AsMap();
    const auto& type = stop_or_route_as_map.at("type").AsString();
    if (type == "Stop") {
      auto [name, coordinates, stop_distances] =
          ProcessInputStop(stop_or_route_as_map);

      for (auto& [destination_name, distance] : stop_distances) {
        auto from = transport_catalogue.FindStop(name);
        auto destination = transport_catalogue.FindStop(destination_name);
        transport_catalogue.AddToStopDistances(from, destination, distance);
      }
    }
  }
}

std::tuple<std::string_view, std::vector<const dom_ents::Stop*>, bool>
JsonReader::ProcessInputRoute(const Dict& route_as_map,
    business_logic::TransportCatalogue& transport_catalogue) const {
  std::string_view route_name = route_as_map.at("name").AsString();
  std::vector<const dom_ents::Stop*> stops;

  for (auto& stop : route_as_map.at("stops").AsArray()) {
    stops.push_back(transport_catalogue.FindStop(stop.AsString()));
  }

  bool circular = route_as_map.at("is_roundtrip").AsBool();
  return std::make_tuple(route_name, stops, circular);
}

MapOutputOperator JsonReader::ProcessInputOutputData(
    const Dict& output_settings_as_map) const {

  dom_ents::OutputSettings map_output_settings;

  map_output_settings.width =
      output_settings_as_map.at("width").AsDouble();

  map_output_settings.height =
      output_settings_as_map.at("height").AsDouble();

  map_output_settings.padding =
      output_settings_as_map.at("padding").AsDouble();

  map_output_settings.stop_label_font_size =
      output_settings_as_map.at("stop_label_font_size").AsInt();

  map_output_settings.stop_radius =
      output_settings_as_map.at("stop_radius").AsDouble();

  map_output_settings.line_width =
      output_settings_as_map.at("line_width").AsDouble();

  map_output_settings.bus_label_font_size  =
      output_settings_as_map.at("bus_label_font_size").AsInt();

  const Array& stop_label_offset =
      output_settings_as_map.at("stop_label_offset").AsArray();

  const Array& bus_label_offset =
      output_settings_as_map.at("bus_label_offset").AsArray();

  map_output_settings.stop_label_offset =
      { stop_label_offset[0].AsDouble(), stop_label_offset[1].AsDouble() };

  map_output_settings.bus_label_offset  =
      { bus_label_offset [0].AsDouble(), bus_label_offset [1].AsDouble() };

  if (output_settings_as_map.at("underlayer_color").IsString()) {
    map_output_settings.underlayer_color =
        output_settings_as_map.at("underlayer_color").AsString();
  } else if (output_settings_as_map.at("underlayer_color").IsArray()) {
    const Array& underlayer_color =
        output_settings_as_map.at("underlayer_color").AsArray();
    if (underlayer_color.size() == 3) {
      map_output_settings.underlayer_color =
          ext_libs::svg::RGB(underlayer_color[0].AsInt(),
                             underlayer_color[1].AsInt(),
                             underlayer_color[2].AsInt());
    } else if (underlayer_color.size() == 4) {
      map_output_settings.underlayer_color =
          ext_libs::svg::RGBO(underlayer_color[0].AsInt(),
                              underlayer_color[1].AsInt(),
                              underlayer_color[2].AsInt(),
                              underlayer_color[3].AsDouble());
    } else {
      throw std::logic_error("underlayer color error");
    }
  } else {
   throw std::logic_error("underlayer color error");
}

  map_output_settings.underlayer_width =
      output_settings_as_map.at("underlayer_width").AsDouble();
  const Array& color_palette =
      output_settings_as_map.at("color_palette").AsArray();
  for (const auto& color : color_palette) {
    if (color.IsString()) {
      map_output_settings.color_palette.push_back(color.AsString());
    }
    else if (color.IsArray()) {
      const Array& color_type = color.AsArray();
      if (color_type.size() == 3) {
        map_output_settings.color_palette.push_back(
            ext_libs::svg::RGB(color_type[0].AsInt(),
                               color_type[1].AsInt(),
                               color_type[2].AsInt()));
      }
      else if (color_type.size() == 4) {
        map_output_settings.color_palette.push_back(
              ext_libs::svg::RGBO (color_type[0].AsInt(),
                                   color_type[1].AsInt(),
                                   color_type[2].AsInt(),
                                   color_type[3].AsDouble()));
      }
      else { throw std::logic_error("color_palette error"); }
    }
    else { throw std::logic_error("color_palette error"); }
  }
  return map_output_settings;
}

TransportRouter::TransportRouterSettings JsonReader::
    ProcessInputRoutingSettings(const ext_libs::json::Node& settings) const {
  return { settings.AsMap().at("bus_wait_time").AsInt(),
           settings.AsMap().at("bus_velocity").AsDouble()};
}

void JsonReader::ProcessStatRequestToOutput(const Node& stat_requests,
    RequestHandler& request_handler) const {
  Array result;

  for (auto& request : stat_requests.AsArray()) {
    const auto& request_map = request.AsMap();
    const auto& type = request_map.at("type").AsString();

    if (type == "Stop" ) {
      result.push_back (OutputStop(request_map,
                                   request_handler).AsMap());
    }
    if (type == "Bus"  ) {
      result.push_back (OutputRoute(request_map,
                                    request_handler).AsMap());
    }
    if (type == "Map"  ) {
      result.push_back (OutputMap(request_map,
                                  request_handler).AsMap());
    }
    if (type == "Route") {
      result.push_back (OutputRouteSequence(request_map,
                                            request_handler).AsMap());
    }
  }
  ext_libs::json::Output( Document{result}, std::cout );
}

const Node JsonReader::OutputStop(const Dict& request_map,
                                  RequestHandler& request_handler) const {

  Node result;
  const std::string& stop_name = request_map.at("name").AsString();
  const int request_id = request_map.at("id").AsInt();

  if (request_handler.GetCatalogue().FindStop(stop_name) == nullptr) {
    result =
        Builder()
          .StartDict()
            .Key("request_id").Value(request_id)
            .Key("error_message").Value("not found")
          .EndDict()
        .Build();
  }
  else {
    Array routes;
    for (const auto& route : request_handler.GetRoutesByStop(stop_name)) {
      routes.push_back(route);
    }

    result =
        Builder()
          .StartDict()
            .Key("request_id").Value(request_id)
            .Key("buses").Value(routes)
          .EndDict()
        .Build();
  }
  return result;
}

const Node JsonReader::OutputRoute(const Dict& request_map,
                                   RequestHandler& request_handler) const {

  Node result;
  const std::string& route_name = request_map.at("name").AsString();
  const int request_id = request_map.at("id").AsInt();

  if (request_handler.GetCatalogue().FindRoute(route_name) == nullptr) {
    result =
        Builder()
          .StartDict()
            .Key("request_id").Value(request_id)
            .Key("error_message").Value("not found")
          .EndDict()
        .Build();
  }
  else {
    const auto& route_stats = request_handler.GetRouteStats(route_name);
      result =
          Builder()
            .StartDict()
              .Key("request_id").Value(request_id)
              .Key("curvature").Value(route_stats.curvature)
              .Key("route_length").Value(route_stats.actual_length)
              .Key("stop_count").Value(route_stats.stops_count)
              .Key("unique_stop_count").Value(route_stats.unique_stops_count)
            .EndDict()
          .Build();
  }
  return result;
}

const Node JsonReader::OutputMap(const Dict& request_map,
                                 RequestHandler& request_handler) const {
  Node result;
  const int request_id = request_map.at("id").AsInt();
  std::ostringstream out;
  ext_libs::svg::Document map = request_handler.OutputMap();
  map.Output(out);

  result =
      Builder()
        .StartDict()
          .Key("request_id").Value(request_id)
          .Key("map").Value(out.str())
        .EndDict()
      .Build();

  return result;
}

const Node JsonReader::OutputRouteSequence(
    const Dict& request_map, RequestHandler& request_handler) const {

  Node route_sequence_node;
  const int request_id = request_map.at("id").AsInt();
  const std::string_view stop_from = request_map.at("from").AsString();
  const std::string_view stop_to = request_map.at("to").AsString();
  const auto& routing = request_handler.BuildRoute(stop_from, stop_to);

  if (!routing) {
    route_sequence_node =
        Builder()
          .StartDict()
            .Key("request_id").Value(request_id)
            .Key("error_message").Value("not found")
          .EndDict()
        .Build();
  }
  else {
    Array items;
    double sum_travel_time = 0.0;

    items.reserve(routing.value().edges.size());

    for (auto& edge_id : routing.value().edges) {
      const ext_libs::graph::Edge<double> edge =
          request_handler.GetTransportRouterGraph().GetEdge(edge_id);
      if (edge.span_count == 0) {
        items.emplace_back(Node(
                Builder()
                  .StartDict()
                    .Key("stop_name").Value(edge.stop_or_route_name)
                    .Key("time").Value(edge.weight)
                    .Key("type").Value("Wait")
                  .EndDict()
                .Build()));

        sum_travel_time += edge.weight;
      }
      else {
        items.emplace_back(Node(
                Builder()
                  .StartDict()
                    .Key("bus").Value(edge.stop_or_route_name)
                    .Key("span_count").Value(edge.span_count)
                    .Key("time").Value(edge.weight)
                    .Key("type").Value("Bus")
                  .EndDict()
                .Build()));

        sum_travel_time += edge.weight;
      }
    }

    route_sequence_node =
        Builder()
          .StartDict()
            .Key("request_id").Value(request_id)
            .Key("total_time").Value(sum_travel_time)
            .Key("items").Value(items)
          .EndDict()
        .Build();
  }

  return route_sequence_node;
}

} // namespace infrastructure - end
} // namespace transport_catalogue - end
