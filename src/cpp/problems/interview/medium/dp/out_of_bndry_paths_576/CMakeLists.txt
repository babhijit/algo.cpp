project(algo.cpp.problems.interview.medium.dp.out_of_boundary_paths_576)

include_directories(include detail)

add_library(${PROJECT_NAME} STATIC detail/path_finder.hpp include/out_of_boundary_paths.hpp out_of_boundary_paths.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)