project(algo.cpp.tests.cpp.problems.interview.medium.bfs_dfs.nested_list_weight_sum_339)
set(TEST_BINARY nested_list_weight_sum_339_tests)
add_executable(${TEST_BINARY} nested_list_weight_sum_339_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.interview.medium.nested_list_weighted_sum_339
)

gtest_discover_tests(${TEST_BINARY})