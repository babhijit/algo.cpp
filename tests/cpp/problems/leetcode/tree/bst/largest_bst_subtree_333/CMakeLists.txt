project(algo.cpp.tests.cpp.problems.leetcode.tree.bst.largest_bst_subtree_333)

set(PROJECT_BINARY largest_bst_subtree_333_tests)

add_executable(${PROJECT_BINARY} leetcode_bst_largest_subtree_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.problems.leetcode.tree.bst.largest_bst_subtree_333
)

gtest_discover_tests(${PROJECT_BINARY})
