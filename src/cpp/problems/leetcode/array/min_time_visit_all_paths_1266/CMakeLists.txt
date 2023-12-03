project(algo.cpp.problems.leetcode.array.min_time_visiting_all_points_1266)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/min_time_visiting_all_points.hpp min_time_visiting_all_points.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)