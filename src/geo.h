#pragma once

#include <cmath>

// domain sctructures - geo - declaration

namespace transport_catalogue {

namespace dom_ents {

namespace geo {

struct Coordinates {
  double lat;
  double lng;

  bool operator==(const Coordinates& other) const {
    return lat == other.lat && lng == other.lng;
  }

  bool operator!=(const Coordinates& other) const {
    return !(*this == other);
  }
};

double ComputeDistance (Coordinates from, Coordinates to);

} // namespace geo - end
} // namespace dom_ents - end
} // namespace transport_catalogue - end
