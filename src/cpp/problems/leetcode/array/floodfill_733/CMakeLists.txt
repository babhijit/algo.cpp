project(algo.cpp.problems.leetcode.array.floodfill_733)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/flood_fill.hpp flood_fill.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)