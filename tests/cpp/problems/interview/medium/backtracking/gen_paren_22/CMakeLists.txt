project(algo.cpp.tests.cpp.problems.interview.medium.backtracking.gen_paren_22)
set(TEST_BINARY gen_paren_22_bt_tests)
add_executable(${TEST_BINARY} test_case.hpp gen_paren_22_bt_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.backtracking.gen_paren_22
)

gtest_discover_tests(${TEST_BINARY})
