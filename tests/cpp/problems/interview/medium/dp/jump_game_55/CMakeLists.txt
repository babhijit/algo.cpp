project(algo.cpp.tests.cpp.problems.interview.medium.dp.jump_game_55)
set(TEST_BINARY jump_game_55_dp_tests)
add_executable(${TEST_BINARY} test_case.hpp jump_game_55_dp_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.dp.jump_game_55
)

gtest_discover_tests(${TEST_BINARY})
