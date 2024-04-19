#pragma once

#include "transport_catalogue.h"
#include "map_renderer.h"
#include "transport_router.h"
#include "transport_catalogue.pb.h"
#include "map_renderer.pb.h"
#include "svg.pb.h"
#include "graph.pb.h"

#include <fstream>

namespace transport_catalogue {

    namespace infrastructure {

        namespace protobuf {

            // --- Serialize ---

            void Serialize(transport_catalogue::business_logic::TransportCatalogue& transport_catalogue_bin, MapOutputOperator, const TransportRouter& transport_router, std::ostream& output);

            void SerializeOutputSettings    (const MapOutputOperator& map_output_operator, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            map_pb::Point    SerializePoint (const ext_libs::svg::Point& point);
            map_pb::ColorVar SerializeColor (const ext_libs::svg::Color& color);
            map_pb::RGB      SerializeRGB   (const ext_libs::svg::RGB&   rgb  );
            map_pb::RGBO     SerializeRGBO  (const ext_libs::svg::RGBO&  rgbo );

            void SerializeStops     (const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            void SerializeDistances (const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            void SerializeRoutes    (const business_logic::TransportCatalogue& transport_catalogue, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);

            graph_pb::Graph SerializeGraph(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);

            transport_router_pb::RoutingSettings SerializeRoutingSettings(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            void SerializeRouter(const TransportRouter& transport_router, transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
                                                                        
            // --- Deserialize ---

            std::tuple
                <
                    business_logic::TransportCatalogue,
                    MapOutputOperator, 
                    TransportRouter,
                    ext_libs::graph::DirectedWeightedGraph<double>,
                    std::map<std::string, ext_libs::graph::VertexId>
                >
                Deserialize(std::istream& input);

            MapOutputOperator DeserializeOutputSettings(transport_catalogue::dom_ents::OutputSettings& output_settings, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            ext_libs::svg::Point DeserializePoint(const map_pb::Point& point_pb);
            ext_libs::svg::Color DeserializeColor(const map_pb::ColorVar& color_pb);

            void DeserializeStops    ( business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            void DeserializeDistances( business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            void DeserializeRoutes   ( business_logic::TransportCatalogue& transport_catalogue, const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);

            ext_libs::graph::DirectedWeightedGraph<double> DeserializeGraph(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);
            std::map<std::string, ext_libs::graph::VertexId> DeserializeStopNameToIds(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);

            TransportRouter DeserializeRoutingSettings(const transport_catalogue_pb::TransportCatalogue& transport_catalogue_pb);

        } // namespace protobuf - end
    } // namespace infrastructure - end
} // namespace transport_catalogue - end