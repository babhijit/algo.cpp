project(algo.cpp.interview.medium.array.k_closest_pts_to_origin_973)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/k_closest_points_to_origin.hpp k_closest_points_to_origin.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)