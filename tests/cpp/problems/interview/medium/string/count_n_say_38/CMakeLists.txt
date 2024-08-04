project(algo.cpp.tests.problems.interview.medium.string.count_n_say_38)

set(TEST_BINARY ${PROJECT_NAME}_tests)
add_executable(${TEST_BINARY} test_case.hpp count_n_say_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.string.count_n_say_38
)

gtest_discover_tests(${TEST_BINARY})
