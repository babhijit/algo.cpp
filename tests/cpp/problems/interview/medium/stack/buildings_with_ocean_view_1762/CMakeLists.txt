project(algo.cpp.tests.cpp.problems.interview.stack.buildings_with_ocean_view_1762)
set(TEST_BINARY buildings_with_ocean_view_1762_tests)
add_executable(${TEST_BINARY} test_case.hpp buildings_with_ocean_view_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.stack.buildings_with_ocean_view_1762
)

gtest_discover_tests(${TEST_BINARY})
