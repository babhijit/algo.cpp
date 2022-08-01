project(algo.cpp.tests.cpp.problems.leetcode.array.floodfill_733)

add_executable(floodfill_733_tests leetcode_flood_fill_733_tests.cpp)

target_link_libraries(
        floodfill_733_tests
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.problems.leetcode.array.floodfill_733
)

gtest_discover_tests(floodfill_733_tests)
