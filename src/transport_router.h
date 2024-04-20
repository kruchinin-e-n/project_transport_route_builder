#pragma once

#include "transport_catalogue.h"
#include "graph.h"
#include "router.h"

#include <memory>
#include <optional>


namespace transport_catalogue {

	namespace infrastructure {

		class TransportRouter {
		public:
			struct TransportRouterSettings {
				int    bus_wait_time; // bus waiting time
				double bus_velocity ; // bus speed
			};

			TransportRouter() = default;
			TransportRouter(const TransportRouterSettings& settings);
			TransportRouter(const TransportRouterSettings& settings, const transport_catalogue::business_logic::TransportCatalogue& transport_catalogue);

			const ext_libs::graph::DirectedWeightedGraph<double>&           BuildGraph (const business_logic::TransportCatalogue& transport_catalogue)      ; // build a graph based on available stops
			const std::optional<ext_libs::graph::Router<double>::RouteInfo> BuildRoute (std::string_view stop_from, std::string_view stop_to         ) const; // build a route based on existing routes
			const ext_libs::graph::DirectedWeightedGraph<double>&           GetGraph   (                                                             ) const; // graph Getter
			const int    GetWaitTime() const;
			const double GetVelocity() const;
			const TransportRouter GetRouterSettings() const;
			const std::map<std::string, ext_libs::graph::VertexId> GetStopNameToIds() const;

			void SetGraph(const ext_libs::graph::DirectedWeightedGraph<double> graph, const std::map<std::string, ext_libs::graph::VertexId> stop_ids);

		private:
			int    bus_wait_time_ = 0;   // bus waiting time
			double bus_velocity_  = 0.0; // bus speed

			std::map<std::string, ext_libs::graph::VertexId> stops_names_to_vertexes_ids_;	// correlating stops with graph vertices
			ext_libs::graph::DirectedWeightedGraph<double>   graph_;						// directed weighted graph from external library

			// Make sure that the graph referenced by the router does not change its address in memory
			std::unique_ptr<ext_libs::graph::Router<double>> router_;						// router class from external library, double means edge weight
		};
	} // namespace infrastructure - end
} // namespace transport_catalogue - end