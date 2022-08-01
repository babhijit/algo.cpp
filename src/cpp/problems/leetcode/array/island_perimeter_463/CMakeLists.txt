project(algo.cpp.problems.leetcode.array.island_perimeter_463)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/island_perimeter.hpp island_perimeter.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)