#include "request_handler.h"

// connecting between input and output dunctions - implementation

namespace transport_catalogue {

	namespace infrastructure {

		dom_ents::RouteStats RequestHandler::GetRouteStats(const std::string_view route_name) const {
			dom_ents::RouteStats route_stats{};
			const dom_ents::Route* route = transport_catalogue_.FindRoute(route_name);

			if (!route) throw std::invalid_argument("bus not found");
			if (route->circular) route_stats.stops_count = route->stops.size();
			else route_stats.stops_count = route->stops.size() * 2 - 1;

			int actual_route_length = 0;
			double geographic_length = 0.0;

			for (size_t i = 0; i < route->stops.size() - 1; ++i) {
				auto from = route->stops[i];
				auto destination = route->stops[i + 1];
				if (route->circular) {
					actual_route_length += transport_catalogue_.GetStopDistance(from, destination);
					geographic_length += dom_ents::geo::ComputeDistance(from->coordinates, destination->coordinates);
				}
				else {
					actual_route_length += transport_catalogue_.GetStopDistance(from, destination) + transport_catalogue_.GetStopDistance(destination, from);
					geographic_length += dom_ents::geo::ComputeDistance(from->coordinates, destination->coordinates) * 2;
				}
			}

			std::unordered_set<std::string_view> unique_stops;
			for (const auto& stop : transport_catalogue_.GetRouteNameToRoute().at(route_name)->stops) {
				unique_stops.insert(stop->name);
			}
			route_stats.unique_stops_count = unique_stops.size();
			route_stats.actual_length = actual_route_length;
			route_stats.curvature = actual_route_length / geographic_length;

			return route_stats;
		}

		const std::set<std::string> RequestHandler::GetRoutesByStop(std::string_view stop_name) const {
			return transport_catalogue_.FindStop(stop_name)->routes_through;
		}

		ext_libs::svg::Document RequestHandler::OutputMap() const {
			return map_output_operator_.MakeDocument(transport_catalogue_.OrderRoutes());
		}

		const business_logic::TransportCatalogue& RequestHandler::GetCatalogue() const {
			return transport_catalogue_;
		}

		const std::optional<ext_libs::graph::Router<double>::RouteInfo> RequestHandler::BuildRoute(std::string_view stop_from, std::string_view stop_to) const {
			return transport_router_.BuildRoute(stop_from, stop_to);
		}

		const ext_libs::graph::DirectedWeightedGraph<double>& RequestHandler::GetTransportRouterGraph() const {
			return transport_router_.GetGraph();
		}
	} // namespace infrastructure - end
} // namespace transport_catalogue - end