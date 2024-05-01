#pragma once

#include "domain.h"

#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <optional>
#include <unordered_set>
#include <set>
#include <map>
#include <string_view>

// core of transport catalogue - declaration

namespace transport_catalogue {

namespace business_logic {

class TransportCatalogue {
  public:

  struct StopDistanceHasher {
    size_t operator() (const std::pair <const dom_ents::Stop*,
                       const dom_ents::Stop*> & points) const {

      // prime_number for effective hasher
      int prime_number = 41;
      // const void* is a pointer to const data of unspecified type
      size_t hash_first = std::hash<const void*>{}(points.first);
      // const void* is a pointer to const data of unspecified type
      size_t hash_second = std::hash<const void*>{}(points.second);
      // hashing
      return hash_first + hash_second * prime_number * prime_number;
    }
  };

  // add stop to stops_, stop_name_to_stop_
  void AddStop(std::string_view stop_name,
               const dom_ents::geo::Coordinates coordinates);

  // add route    | to routes_, route_name_to_route_
  void AddRoute(std::string_view route_name,
                const std::vector<const dom_ents::Stop*> & stops,
                bool circular);

  // add distance | to stop_distances_
  void AddToStopDistances(const dom_ents::Stop* from,
                          const dom_ents::Stop* to,
                          const double distance);

  // find route by route_name from route_name_to_route_
  const dom_ents::Route* FindRoute(std::string_view route_name) const;

  // find stop by stop_name from stop_name_to_stop_
  const dom_ents::Stop* FindStop(std::string_view stop_name) const;

  const dom_ents::RouteStats GetRouteStats(std::string_view route_name) const;

  const std::set<std::string> GetRoutesByStop(std::string_view stop_name) const;

  int GetStopDistance(const dom_ents::Stop* from,
                      const dom_ents::Stop* to) const;

  std::unordered_map<std::pair<const dom_ents::Stop*, const dom_ents::Stop*>,
                     double,
                     StopDistanceHasher> GetStopDistances() const;

  std::unordered_map<std::string_view,
                     const dom_ents::Route*> GetRouteNameToRoute() const;

  const std::map<std::string_view, const dom_ents::Route*> OrderRoutes() const;

  const std::map<std::string_view, const dom_ents::Stop*> OrderStops() const;

  private:

  std::deque<dom_ents::Route> routes_;

  std::deque<dom_ents::Stop>  stops_;

  std::unordered_map<std::string_view,
                     const dom_ents::Route*> route_name_to_route_;

  std::unordered_map<std::string_view,
                     const dom_ents::Stop* > stop_name_to_stop_;

  std::unordered_map<std::pair<const dom_ents::Stop*, const dom_ents::Stop*>,
                     double,
                     StopDistanceHasher> stop_distances_;
};

} // namespace business_logic - end
} // namespace transport_catalogue - end
