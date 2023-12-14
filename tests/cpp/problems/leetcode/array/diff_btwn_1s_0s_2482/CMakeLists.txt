project(algo.cpp.tests.cpp.problems.leetcode.array.diff_btwn_1s_0s_2482)

set(TEST_BINARY diff_btwn_1s_0s_2482_tests)

add_executable(${TEST_BINARY}
        test_case.hpp
        diff_btwn_1s_0s_2482_tests.cpp)

target_link_libraries(${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.diff_btwn_1s_0s_2482)

gtest_discover_tests(${TEST_BINARY})