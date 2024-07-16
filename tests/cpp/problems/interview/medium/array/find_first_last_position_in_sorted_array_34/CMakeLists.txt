project(algo.cpp.tests.interview.medium.find_first_last_position_in_sorted_array_34)

set(PROJECT_BINARY find_first_last_position_in_sorted_array_34_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        find_first_last_position_in_sorted_array_34_tests.cpp
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
        algo.cpp.interview.medium.find_first_last_position_in_sorted_array_34
)

gtest_discover_tests(${PROJECT_BINARY})
