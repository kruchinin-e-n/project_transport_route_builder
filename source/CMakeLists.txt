cmake_minimum_required(VERSION 3.11)
project(MakeTransportCataloqueBase CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)
find_package(Threads REQUIRED)

# According to program application layers (described in main.cpp and domain.cpp)

set(SOURCE_DIR src)

set(MAIN_FILES			"${SOURCE_DIR}/main.cpp")
set(DOMAIN_FILES		"${SOURCE_DIR}/domain.h"
						"${SOURCE_DIR}/domain.cpp")
set(GEO_FILES			"${SOURCE_DIR}/geo.h"
						"${SOURCE_DIR}/geo.cpp")
set(JSON_FILES			"${SOURCE_DIR}/json.h"
						"${SOURCE_DIR}/json.cpp")
set(SVG_FILES			"${SOURCE_DIR}/svg.h"
						"${SOURCE_DIR}/svg.cpp")
set(GRAPH_FILES			"${SOURCE_DIR}/graph.h"
						"${SOURCE_DIR}/ranges.h"
						"${SOURCE_DIR}/router.h")
set(JSON_READER			"${SOURCE_DIR}/json_reader.h"
						"${SOURCE_DIR}/json_reader.cpp")
set(JSON_BUILDER		"${SOURCE_DIR}/json_builder.h"
						"${SOURCE_DIR}/json_builder.cpp")
set(MAP_RENDER			"${SOURCE_DIR}/map_renderer.h"
						"${SOURCE_DIR}/map_renderer.cpp")
set(REQUEST_HANDLER		"${SOURCE_DIR}/request_handler.h"
						"${SOURCE_DIR}/request_handler.cpp")
set(SERIALIZATION		"${SOURCE_DIR}/serialization.h"
						"${SOURCE_DIR}/serialization.cpp")
set(TRANSPORT_CATALOGUE	"${SOURCE_DIR}/transport_catalogue.h"
						"${SOURCE_DIR}/transport_catalogue.cpp")
set(TRANSPORT_ROUTER	"${SOURCE_DIR}/transport_router.h"
						"${SOURCE_DIR}/transport_router.cpp")

protobuf_generate_cpp(	PROTO_SRCS
						PROTO_HDRS
						"${SOURCE_DIR}/transport_catalogue.proto"
						"${SOURCE_DIR}/map_renderer.proto"
						"${SOURCE_DIR}/svg.proto"
						"${SOURCE_DIR}/graph.proto"
						"${SOURCE_DIR}/transport_router.proto")

# According to program application layers (described in main.cpp and domain.cpp)
add_executable(transport_catalogue	${MAIN_FILES}
									${PROTO_SRCS}
									${PROTO_HDRS}
									${DOMAIN_FILES}
									${GEO_FILES}
									${JSON_FILES}
									${SVG_FILES}
									${GRAPH_FILES}
									${JSON_READER}
									${JSON_BUILDER}
									${MAP_RENDER}
									${REQUEST_HANDLER}
									${SERIALIZATION}
									${TRANSPORT_CATALOGUE}
									${TRANSPORT_ROUTER})

source_group("Main files"			FILES ${MAIN_FILES})
source_group("Domain files"			FILES ${DOMAIN_FILES})
source_group("Geo files"			FILES ${GEO_FILES})
source_group("Json files"			FILES ${JSON_FILES})
source_group("SVG files"			FILES ${SVG_FILES})
source_group("Graph files"			FILES ${GRAPH_FILES})
source_group("Json reader"			FILES ${JSON_READER})
source_group("Json builder"			FILES ${JSON_BUILDER})
source_group("Map renderer"			FILES ${MAP_RENDER})
source_group("Request handler"		FILES ${REQUEST_HANDLER})
source_group("Serialization"		FILES ${SERIALIZATION})
source_group("Transport catalogue"	FILES ${TRANSPORT_CATALOGUE})
source_group("Transport router"		FILES ${TRANSPORT_ROUTER})
source_group("Proto srcs"			FILES ${PROTO_SRCS})
source_group("Proto hdrs"			FILES ${PROTO_HDRS})

if(CMAKE_SYSTEM_NAME MATCHES "^MINGW")
	set(SYSTEM_LIBS -lstdc++)
else()
	set(SYSTEM_LIBS)
endif()

target_include_directories(transport_catalogue PUBLIC ${Protobuf_INCLUDE_DIRS})
target_include_directories(transport_catalogue PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

string(REPLACE	"protobuf.lib"	"protobufd.lib"	"Protobuf_LIBRARY_DEBUG"	"${Protobuf_LIBRARY_DEBUG}")
string(REPLACE	"protobuf.a"	"protobufd.a"	"Protobuf_LIBRARY_DEBUG"	"${Protobuf_LIBRARY_DEBUG}")

target_link_libraries(transport_catalogue	${SYSTEM_LIBS})
target_link_libraries(transport_catalogue	"$<IF:$<CONFIG:Debug>,${Protobuf_LIBRARY_DEBUG},${Protobuf_LIBRARY}>" 
											Threads::Threads)

#cmake ../source -G "Visual Studio 17 2022" -DCMAKE_PREFIX_PATH=D:/Installed_programs/Protobuf 
#cmake --build .
#or command for Visual Studio
#cmake --build . --config Debug

#-DCMAKE_BUILD_TYPE=<mode>