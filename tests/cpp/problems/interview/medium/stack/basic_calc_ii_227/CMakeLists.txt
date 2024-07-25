project(algo.cpp.tests.cpp.problems.interview.stack.basic_calculator_ii_224)
set(TEST_BINARY basic_calculator_ii_224_tests)
add_executable(${TEST_BINARY} test_case.hpp basic_calculator_ii_224_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.stack.basic_calc2_227
)

gtest_discover_tests(${TEST_BINARY})
