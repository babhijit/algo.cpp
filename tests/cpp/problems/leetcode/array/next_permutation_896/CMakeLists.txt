project(algo.cpp.tests.cpp.problems.leetcode.array.next_permutation_896)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(next_permutation_896_tests next_permutation_896_tests.cpp)

target_link_libraries(
        next_permutation_896_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.next_permutation_896
)

gtest_discover_tests(next_permutation_896_tests)
