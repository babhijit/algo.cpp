project(algo.cpp.tests.cpp.problems.interview.greedy.max_swap_670)

set(TEST_BINARY ${PROJECT_NAME}_tests)
add_executable(${TEST_BINARY} test_case.hpp max_swap_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.greedy.max_swap_670
)

gtest_discover_tests(${TEST_BINARY})
