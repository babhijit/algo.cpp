project(algo.cpp.tests.cpp.problems.leetcode.array.buy_2_choc_2706)

set(TEST_BINARY buy_2_choc_2706_tests)

add_executable(${TEST_BINARY}
        test_case.hpp
        buy_2_choc_2706_tests.cpp)

target_link_libraries(${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.buy_2_choc_2706)

gtest_discover_tests(${TEST_BINARY})