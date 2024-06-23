project(algo.cpp.tests.cpp.problems.leetcode.tree.binary_tree.btree_vert_order_traversal_314)

set(PROJECT_BINARY btree_vert_order_traversal_314)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} btree_vert_order_traversal_314_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.leetcode.tree.binary_tree.bt_vert_order_traversal_314
)

gtest_discover_tests(${PROJECT_BINARY})
