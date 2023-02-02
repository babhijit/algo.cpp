project(algo.cpp.tests.cpp.problems.leetcode.list.remove_nth_node_from_end_19)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(remove_nth_node_from_end_19_tests remove_nth_node_from_end_19_tests.cpp)

target_link_libraries(
        remove_nth_node_from_end_19_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.list.remove_nth_node_from_end_19
)

gtest_discover_tests(remove_nth_node_from_end_19_tests)
