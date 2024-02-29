/*
 Program application layers:

 1. Business logic
    - module transport catalogue
 2. Domain entities
    - module domain
 3. Infrastructure
    - module json_reader
    - module json_builder
    - module map_renderer
    - module request handler
    - module transport router
    - module serialization
 4. Entry point
    - module main
 5. External libraries
    - module json
    - module svg
    - module graph
    - module router
    - module ranges
*/

#include "json_reader.h"
#include "transport_catalogue.h"
#include "serialization.h"

#include <fstream>
#include <iostream>
#include <string_view>

using namespace std::literals;

void PrintUsage(std::ostream& stream = std::cerr) {
    stream << "Usage: transport_catalogue [make_base|process_requests]\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        PrintUsage();
        return 1;
    }

    const std::string_view mode(argv[1]);

    if (mode == "make_base"sv) {

        transport_catalogue::infrastructure::JsonReader request(std::cin); // json input

        // --- fill catalogue
        transport_catalogue::business_logic::TransportCatalogue transport_catalogue;;
        request.ProcessInputCatalogueData(transport_catalogue);

        // --- fill router ---
        const auto& routing_settings = request.ProcessInputRoutingSettings(request.ProcessRoutingSettings());
        const transport_catalogue::infrastructure::TransportRouter transport_router = { routing_settings, transport_catalogue };

        // --- fill renderer ---
        const auto& output_settings = request.ProcessOutputSettings();
        const transport_catalogue::infrastructure::MapOutputOperator map_output_operator = request.ProcessInputOutputData(output_settings.AsMap());

        // --- fill serialization ---
        const auto& serialization_settings = request.ProcessSerializationSettings();

        // --- serialize base into file ---
        std::ofstream output_file(serialization_settings.AsMap().at("file"s).AsString(), std::ios::binary);
        if (output_file.is_open()) { transport_catalogue::infrastructure::protobuf::Serialize(transport_catalogue, map_output_operator, transport_router, output_file); }

    }
    else if (mode == "process_requests"sv) {

        transport_catalogue::infrastructure::JsonReader request(std::cin); // json input

        // --- deserialize transport base from file ---
        std::ifstream transport_catalogue_bin(request.ProcessSerializationSettings().AsMap().at("file"s).AsString(), std::ios::binary);
        if (transport_catalogue_bin) {
            auto [transport_catalogue, map_output_operator, router, graph, stop_name_to_ids ] = transport_catalogue::infrastructure::protobuf::Deserialize(transport_catalogue_bin);
            router.SetGraph(graph, stop_name_to_ids);
            transport_catalogue::infrastructure::RequestHandler request_handler = { map_output_operator,transport_catalogue, router };

        // --- processing requests ---
            const auto& stat_requests = request.ProcessStatRequests();
            request.ProcessStatRequestToOutput(stat_requests, request_handler);
        }
    }
    else {
        PrintUsage();
        return 1;
    }
}