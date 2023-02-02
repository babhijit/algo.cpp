project(algo.cpp.tests.cpp.problems.leetcode.array.longest_consecutive_seq_128)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(longest_consecutive_seq_128_tests longest_consecutive_seq_128_tests.cpp)

target_link_libraries(
        longest_consecutive_seq_128_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.longest_consecutive_seq_128
)

gtest_discover_tests(longest_consecutive_seq_128_tests)
