project(algo.cpp.tests.interview.medium.accounts_merge_721)

set(PROJECT_BINARY test_algo_medium_accounts_merge_721_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        acc_merge_tests.cpp
)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.interview.medium.bfs_dfs.accounts_merge_721
)

gtest_discover_tests(${PROJECT_BINARY})
