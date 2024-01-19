project(algo.cpp.tests.cpp.problems.leetcode.maths.combination_sum_39)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY climbing_stairs_70)

add_executable(${PROJECT_BINARY} test_case.hpp climbing_stairs_70_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.maths.climbing_stairs_70
)

gtest_discover_tests(${PROJECT_BINARY})
