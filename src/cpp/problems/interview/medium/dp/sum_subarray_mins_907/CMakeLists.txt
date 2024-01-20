project(algo.cpp.problems.interview.medium.dp.sum_min_subarray_907)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/dp_sum_min_subarray.hpp dp_sum_min_subarray.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)