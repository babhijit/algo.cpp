project(algo.cpp.tests.cpp.problems.leetcode.pq.longest_cont_subarr_absdiff_le_limit_1438)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(longest_cont_subarr_absdiff_le_limit_1438_tests longest_cont_subarr_absdiff_le_limit_1438_tests.cpp)

target_link_libraries(
        longest_cont_subarr_absdiff_le_limit_1438_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.pq.longest_cont_subarr_absdiff_le_limit_1438
)

gtest_discover_tests(longest_cont_subarr_absdiff_le_limit_1438_tests)
