project(algo.cpp.tests.interview.medium.array.search_in_rotated_array_33)

set(PROJECT_BINARY test_algo_medium_array_search_in_rotated_array_33_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        search_in_rotated_array_33_tests.cpp
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
        algo.cpp.interview.medium.search_in_rotated_array_33
)

gtest_discover_tests(${PROJECT_BINARY})
