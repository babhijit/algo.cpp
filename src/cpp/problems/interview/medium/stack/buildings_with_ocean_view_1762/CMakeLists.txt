project(algo.cpp.problems.interview.medium.stack.buildings_with_ocean_view_1762)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/ocean_view_buildings.hpp ocean_view_buildings.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)