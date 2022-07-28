project(algo.cpp)

add_library(${PROJECT_NAME} INTERFACE)

set(GRAPH_SOURCES ds/graph/bag.hpp
        ds/graph/graph.hpp
        ds/graph/depth_first_paths.hpp
        ds/graph/depth_first_search.hpp)

target_sources(${PROJECT_NAME} INTERFACE ${GRAPH_SOURCES})

target_include_directories(${PROJECT_NAME} INTERFACE ds)
