project(algo.cpp.problems.leetcode.maths.combination_sum_39)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/combination_sum.h combination_sum.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)