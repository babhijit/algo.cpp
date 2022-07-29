project(algo.cpp.ds)

include_directories(
        include/sequence    # Sequence
        include/graph       # Undirected Graph
        include/digraph     # Directed Graph
        include/utils       # Utility functions
)

# Sequence Data Structures
set(SEQ_HEADERS include/sequence/bag.hpp)
set(SEQ_SOURCES impl/sequence/bag.cpp)

# Graph data structures
set(GRAPH_HEADERS
        include/graph/graph.hpp
        include/graph/depth_first_search.hpp
        include/graph/depth_first_paths.hpp
        include/graph/breadth_first_paths.hpp
        include/graph/cc.hpp
        include/graph/cycle.hpp
        include/graph/two_color.hpp)

set(GRAPH_SOURCES impl/graph/graph.cpp
        impl/graph/depth_first_search.cpp
        impl/graph/depth_first_paths.cpp
        impl/graph/breadth_first_paths.cpp
        impl/graph/cc.cpp
        impl/graph/cycle.cpp
        impl/graph/two_color.cpp)

# Digraph Data Structures
set(DIGRAPH_HEADERS
        include/digraph/digraph.hpp
        include/utils/reverse_graph.hpp
        include/digraph/directed_dfs.hpp
        include/digraph/directed_cycle.hpp)

set(DIGRAPH_SOURCES
        impl/digraph/digraph.cpp
        impl/digraph/directed_dfs.cpp
        impl/digraph/directed_cycle.cpp)

# Utility Functions
set(UTIL_HEADERS include/utils/reverse_graph.hpp include/utils/graph_loader.hpp)

# Library Headers and Sources
set(LIB_HEADERS ${SEQ_HEADERS} ${GRAPH_HEADERS} ${DIGRAPH_HEADERS} ${UTIL_HEADERS})
set(LIB_SOURCES ${SEQ_SOURCES} ${GRAPH_SOURCES} ${DIGRAPH_SOURCES})

# Library
add_library(${PROJECT_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)