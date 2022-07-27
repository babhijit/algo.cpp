project(algo.cpp)

add_library(${PROJECT_NAME}
        main.cpp
        ds/graph/bag.hpp
        ds/graph/graph.hpp
        ds/graph/depth_first_search.hpp
        ds/graph/paths.hpp)
