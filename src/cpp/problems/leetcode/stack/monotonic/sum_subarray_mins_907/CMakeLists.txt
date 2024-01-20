project(algo.cpp.problems.leetcode.stack.sum_min_subarray_907)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/sum_min_subarray.hpp sum_min_subarray.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)