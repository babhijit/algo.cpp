project(algo.cpp.tests.interview.medium.array.three_sum_closet_16)

set(PROJECT_BINARY test_algo_medium_array_three_sum_closet_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        three_sum_closest_test.cpp
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
        algo.cpp.interview.medium.three_sum_closet_16
)

gtest_discover_tests(${PROJECT_BINARY})
