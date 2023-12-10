project(algo.cpp.tests.cpp.problems.leetcode.strings.largest_odd_num_in_str_1903)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY largest_odd_num_in_str_1903_tests)

add_executable(${PROJECT_BINARY} test_case.hpp largest_odd_num_in_str_1903_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.strings.largest_odd_num_in_str_1903
)

gtest_discover_tests(${PROJECT_BINARY})
