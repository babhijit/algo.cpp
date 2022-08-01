project(algo.cpp.tests.cpp.problems.leetcode.array.island_perimeter_463)

add_executable(island_perimeter_463_tests island_perimeter_463_tests.cpp)

target_link_libraries(
        island_perimeter_463_tests
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.problems.leetcode.array.island_perimeter_463
)

gtest_discover_tests(island_perimeter_463_tests)
