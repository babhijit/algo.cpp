project(algo.cpp.tests.cpp.problems.leetcode.list.merge_k_sorted_lists_23)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY merge_k_sorted_lists_23_tests)

add_executable(${PROJECT_BINARY} merge_k_sorted_lists_23_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.list.merge_k_sorted_23
)

gtest_discover_tests(${PROJECT_BINARY})
