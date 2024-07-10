project(algo.cpp.tests.cpp.problems.interview.medium.backtracking.letter_comb_phone_17)
set(TEST_BINARY length_comb_phone_17_tests)
add_executable(${TEST_BINARY} test_case.hpp letter_comb_phone_17_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.backtracking.letter_comb_phone_17
)

gtest_discover_tests(${TEST_BINARY})
