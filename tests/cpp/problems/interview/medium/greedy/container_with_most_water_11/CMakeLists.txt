project(algo.cpp.tests.cpp.problems.interview.medium.greedy.container_with_most_water_11)
set(TEST_BINARY container_with_most_water_11_tests)
add_executable(${TEST_BINARY} test_case.hpp container_with_most_water_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.greedy.container_with_most_water_11
)

gtest_discover_tests(${TEST_BINARY})
