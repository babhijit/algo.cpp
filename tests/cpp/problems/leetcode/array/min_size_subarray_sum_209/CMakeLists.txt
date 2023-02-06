project(algo.cpp.tests.cpp.problems.leetcode.array.min_size_subarray_sum_209)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})


add_executable(min_size_subarray_sum_binary_search_209_tests
        min_size_subarray_sum_binary_search_209_tests.cpp
        test_case.hpp
        )

target_link_libraries(
        min_size_subarray_sum_binary_search_209_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.min_size_subarray_sum_209
)

gtest_discover_tests(min_size_subarray_sum_binary_search_209_tests)



add_executable(min_size_subarray_sum_sliding_window_209_tests
        min_size_subarray_sum_sliding_window_209_tests.cpp
        test_case.hpp
        )

target_link_libraries(
        min_size_subarray_sum_sliding_window_209_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.min_size_subarray_sum_209
)

gtest_discover_tests(min_size_subarray_sum_sliding_window_209_tests)
