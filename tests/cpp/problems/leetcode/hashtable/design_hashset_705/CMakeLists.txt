project(algo.cpp.tests.cpp.problems.leetcode.hashtable.design_hashset_705)

set(PROJECT_BINARY design_hashset_705_tests)

add_executable(${PROJECT_BINARY} leetcode_design_hashset_705_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.problems.leetcode.hashtable.design_hashset_705
)

gtest_discover_tests(${PROJECT_BINARY})
