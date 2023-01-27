project(algo.cpp.tests.cpp.problems.leetcode.array.game_of_life_289)

add_executable(game_of_life_289_tests game_of_life_289_tests.cpp)

target_link_libraries(
        game_of_life_289_tests
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.problems.leetcode.array.game_of_life_289
)

gtest_discover_tests(game_of_life_289_tests)
