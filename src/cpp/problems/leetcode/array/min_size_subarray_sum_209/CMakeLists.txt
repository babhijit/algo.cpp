project(algo.cpp.problems.leetcode.array.min_size_subarray_sum_209)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/min_size_subarray_sum.hpp
        include/abstract_min_size_subarray_sum.hpp
        include/min_size_subarray_sum_binary_search.hpp
        min_size_subarray_sum_binary_search.cpp
        include/min_size_subarray_sum_sliding_window.hpp
        min_size_subarray_sum_sliding_window.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)