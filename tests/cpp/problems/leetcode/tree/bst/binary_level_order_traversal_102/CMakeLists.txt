project(algo.cpp.tests.cpp.problems.leetcode.tree.bst.binary_level_order_traversal_102)

set(PROJECT_BINARY binary_level_order_traversal_102_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} leetcode_bst_level_order_traversal_test.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.leetcode.tree.bst.binary_level_order_traversal_102
)

gtest_discover_tests(${PROJECT_BINARY})
