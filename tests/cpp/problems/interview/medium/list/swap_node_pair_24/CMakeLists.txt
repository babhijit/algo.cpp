project(algo.cpp.tests.cpp.problems.interview.medium.list.swap_node_pair_24)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY swap_node_pair_24_tests)

add_executable(${PROJECT_BINARY} swap_node_pair_24_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.interview.medium.list.swap_node_pair_24
)

gtest_discover_tests(${PROJECT_BINARY})
