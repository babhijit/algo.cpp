project(algo.cpp.tests.cpp.problems.leetcode.array.min_domino_rotations_1007)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(min_domino_rotations_1007_tests min_domino_rotations_1007_tests.cpp)

target_link_libraries(
        min_domino_rotations_1007_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.min_domino_rotations_1007
)

gtest_discover_tests(min_domino_rotations_1007_tests)
