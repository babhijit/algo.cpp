project(algo.cpp.tests.cpp.problems.interview.medium.tree.bst_to_sorted_doublylinkedlist_426)

set(PROJECT_BINARY interview_medium_sum_bst2dll_426_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} bst2dll_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.interview.medium.tree.bst_to_sorted_doublylinkedlist_426
)

gtest_discover_tests(${PROJECT_BINARY})
