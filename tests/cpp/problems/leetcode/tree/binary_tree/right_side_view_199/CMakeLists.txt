project(algo.cpp.tests.cpp.problems.leetcode.tree.binary_tree.right_side_view_199)

set(PROJECT_BINARY right_side_view_199_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} right_side_view_199_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.leetcode.tree.binary_tree.right_side_view_199
)

gtest_discover_tests(${PROJECT_BINARY})
