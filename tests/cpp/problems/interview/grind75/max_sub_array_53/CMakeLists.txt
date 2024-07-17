project(algo.cpp.tests.interview.grind75.max_sub_array_53)

set(PROJECT_BINARY test_algo_grind_75max_sub_array_53_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        grind_75_max_sub_array_53_tests.cpp
)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.interview.grind75.max_sub_array_53
)

gtest_discover_tests(${PROJECT_BINARY})
