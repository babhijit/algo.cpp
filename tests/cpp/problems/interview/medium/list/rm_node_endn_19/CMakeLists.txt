project(algo.cpp.tests.cpp.problems.interview.medium.list.rm_node_endn_19_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY rm_node_endn_19_tests)

add_executable(${PROJECT_BINARY} rm_node_endn_19_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.interview.medium.list.rm_node_endn_19
)

gtest_discover_tests(${PROJECT_BINARY})
