project(algo.cpp.ds)

include_directories(include/graph)

set(DS_HEADERS include/graph/bag.hpp
        include/graph/graph.hpp
        include/graph/depth_first_search.hpp
        include/graph/depth_first_paths.hpp
        include/graph/breadth_first_paths.hpp
        )

set(DS_SOURCES impl/graph/graph.cpp
        impl/graph/depth_first_search.cpp
        impl/graph/depth_first_paths.cpp
        impl/graph/breadth_first_paths.cpp
        )

add_library(${PROJECT_NAME} STATIC ${DS_HEADERS} ${DS_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)