project(algo.cpp.tests.cpp.problems.interview.medium.tree.check_tree_completeness_958)

set(PROJECT_BINARY ${PROJECT_NAME})

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} complete_tree_check_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.interview.medium.tree.check_tree_completeness_958
)

gtest_discover_tests(${PROJECT_BINARY})
