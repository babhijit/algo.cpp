project(algo.interview.medium.array.continuous_subarray_sum_523)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/subarray_sum.hpp subarray_sum.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)