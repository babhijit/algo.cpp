project(algo.cpp.tests.cpp.problems.leetcode.set.longest_cont_subarr_absdiff_le_limit_1438)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set (BINARY longest_cont_subarr_absdiff_le_limit_1438_set_tests)

add_executable(${BINARY} longest_cont_subarr_absdiff_le_limit_1438_tests.cpp)

target_link_libraries(
        ${BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.set.longest_cont_subarr_absdiff_le_limit_1438
)

gtest_discover_tests(${BINARY})
