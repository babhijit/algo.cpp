project(algo.cpp.tests.cpp.problems.leetcode.tree.binary_tree.flatten_binary_tree_to_list_114)

set(PROJECT_BINARY flatten_binary_tree_to_list_114_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} flatten_binary_tree_to_list_114_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.leetcode.tree.binary_tree.flatten_binary_tree_to_list_114
)

gtest_discover_tests(${PROJECT_BINARY})
