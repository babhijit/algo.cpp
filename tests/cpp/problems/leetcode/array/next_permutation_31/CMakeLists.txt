project(algo.cpp.tests.cpp.problems.leetcode.array.next_permutation_31)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY next_permutation_31_tests)

add_executable(${PROJECT_BINARY} next_permutation_31_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.next_permutation_31
)

gtest_discover_tests(${PROJECT_BINARY})
