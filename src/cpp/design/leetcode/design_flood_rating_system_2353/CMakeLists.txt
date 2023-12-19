project(algo.cpp.design.leetcode.design_flood_rating_system_2353)


include_directories(include)

add_library(${PROJECT_NAME} STATIC include/rated_food.hpp include/food_rating_system.hpp food_rating_system.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)