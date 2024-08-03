project(algo.cpp.tests.interview.medium.continuous_subarray_sum_523)

set(PROJECT_BINARY test_algo_medium_continuous_subarray_sum_523_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        contiguous_subarray_sum_test.cpp
)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.interview.medium.array.continuous_subarray_sum_523
)

gtest_discover_tests(${PROJECT_BINARY})
