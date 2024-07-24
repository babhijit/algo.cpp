project(algo.cpp.tests.cpp.problems.interview.medium.tree.sum_root2leaf_nos_129)

set(PROJECT_BINARY interview_medium_sum_root2leaf_nos_129)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} sum_root2leaf_nos_129_tests.cpp test_case.hpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.interview.medium.tree.sum_root2leaf_nos_129
)

gtest_discover_tests(${PROJECT_BINARY})
