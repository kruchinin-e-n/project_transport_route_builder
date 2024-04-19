#define _USE_MATH_DEFINES
#include "geo.h"

#include <cmath>

// domain sctructures - geo - implementation

namespace transport_catalogue {

    namespace dom_ents {

        namespace geo {

            double ComputeDistance (Coordinates from, Coordinates to) {
                using namespace std;
                if (from == to) return 0;
                static const double dr = M_PI / 180.;
                static const int earth_rd = 6371000;
                return acos 
                       (
                           sin(from.lat * dr) * sin(to.lat * dr) 
                           + 
                           cos(from.lat * dr) * cos(to.lat * dr) * cos(abs(from.lng - to.lng) * dr)
                       )
                       * 
                       earth_rd;
            }
        } // namespace geo - end
    } // namespace dom_ents - end
} // namespace transport_catalogue - end