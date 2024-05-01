#include "transport_catalogue.h"

// core of transport catalogue - imlementation

namespace transport_catalogue {

namespace business_logic {

void TransportCatalogue::AddStop(
    std::string_view stop_name,
    const dom_ents::geo::Coordinates coordinates) {
  stops_.push_back({ std::string(stop_name), coordinates, {/*route trough*/} });
  stop_name_to_stop_[stops_.back().name] = &stops_.back();
}

void TransportCatalogue::AddRoute(
    std::string_view route_name,
    const std::vector<const dom_ents::Stop*> & stops,
    bool is_circle) {

  routes_.push_back({ std::string(route_name), stops, is_circle });
  route_name_to_route_[routes_.back().name] = &routes_.back();

  for (const auto& stop1 : stops) {
    for (auto& stop2 : stops_) {
      if (stop2.name == stop1->name) {
        stop2.routes_through.insert(std::string(route_name));
      }
    }
  }
}

const dom_ents::Route* TransportCatalogue::FindRoute(
    std::string_view route_name) const {

  return route_name_to_route_.count(route_name)
         ? route_name_to_route_.at(route_name)
         : nullptr;
}

const dom_ents::Stop* TransportCatalogue::FindStop(
    std::string_view stop_name) const {

  return stop_name_to_stop_.count(stop_name)
         ? stop_name_to_stop_.at(stop_name)
         : nullptr;
}

const dom_ents::RouteStats TransportCatalogue::GetRouteStats(
    std::string_view route_name) const {

  dom_ents::RouteStats route_stats{};
  const dom_ents::Route* route = FindRoute(route_name);

  if (route->circular) { route_stats.stops_count = route->stops.size(); }
  else { route_stats.stops_count = route->stops.size() * 2 - 1; }

  double actual_route_length = 0.0;
  double geographic_length = 0.0;

  for (size_t i = 0; i < route->stops.size() - 1; ++i) {
    auto from = route->stops[i];
    auto to = route->stops[i + 1];
    if (route->circular) {
      actual_route_length += GetStopDistance(from, to);
      geographic_length +=
          dom_ents::geo::ComputeDistance(from->coordinates, to->coordinates);
    }
    else {
      actual_route_length +=
          GetStopDistance(from, to) + GetStopDistance(to, from);
      geographic_length +=
          dom_ents::geo::ComputeDistance(from->coordinates, to->coordinates)
              * 2;
    }
  }

  std::unordered_set<std::string_view> unique_stops;
  for (const auto& stop : route_name_to_route_.at(route_name)->stops) {
    unique_stops.insert(stop->name);
  }
  route_stats.unique_stops_count = unique_stops.size();

  route_stats.actual_length = actual_route_length;
  route_stats.curvature = actual_route_length / geographic_length;

  return route_stats;
}

const std::set<std::string> TransportCatalogue::GetRoutesByStop(
    std::string_view stop_name) const {
  return stop_name_to_stop_.at(stop_name)->routes_through;
}

void TransportCatalogue::AddToStopDistances(
    const dom_ents::Stop* from,
    const dom_ents::Stop* to,
    const double distance) {
  stop_distances_[{from, to}] = distance;
}

int TransportCatalogue::GetStopDistance(
    const dom_ents::Stop* from,
    const dom_ents::Stop* to) const {

  if (stop_distances_.count({ from, to })) {
    return stop_distances_.at({ from, to });
  }
  else if (stop_distances_.count({ to, from })) {
    return stop_distances_.at({ to, from });
  }
  else { return 0.; }
}

std::unordered_map<
    std::pair<const dom_ents::Stop*,const dom_ents::Stop*>,
    double,
    TransportCatalogue::StopDistanceHasher>
        TransportCatalogue::GetStopDistances() const {
  return stop_distances_;
}

const std::map<std::string_view,
               const dom_ents::Route*> TransportCatalogue::OrderRoutes() const {

  std::map<std::string_view, const dom_ents::Route*> ordered_routes;
  for (const auto& route : route_name_to_route_) {
    ordered_routes.emplace(route);
  }
  return ordered_routes;
}

const std::map<std::string_view, const dom_ents::Stop*>
    TransportCatalogue::OrderStops() const {

  std::map<std::string_view, const dom_ents::Stop*> ordered_stops;
  for (const auto& stop : stop_name_to_stop_) {
    ordered_stops.emplace(stop);
  }
  return ordered_stops;
}

std::unordered_map<std::string_view, const dom_ents::Route*>
    TransportCatalogue::GetRouteNameToRoute() const {
  return route_name_to_route_;
}

} // namespace business_logic - end
} // namespace transport_catalogue - end
