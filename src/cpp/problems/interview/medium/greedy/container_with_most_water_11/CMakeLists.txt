project(algo.cpp.problems.interview.medium.greedy.container_with_most_water_11)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/container_with_most_water.hpp container_with_most_water.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)