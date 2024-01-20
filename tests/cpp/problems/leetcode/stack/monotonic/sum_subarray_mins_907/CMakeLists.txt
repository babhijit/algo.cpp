project(algo.cpp.tests.cpp.problems.leetcode.stack.sum_subarray_mins_907)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY sum_subarray_mins_907)

add_executable(${PROJECT_BINARY} test_case.hpp sum_subarray_mins_907_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.stack.sum_min_subarray_907
)

gtest_discover_tests(${PROJECT_BINARY})
