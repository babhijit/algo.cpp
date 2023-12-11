project(algo.cpp.problems.leetcode.array.elm_appear_more_than_quarter_sorted_array_1287)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/elm_in_sorted_array.hpp  elm_in_sorted_array.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)