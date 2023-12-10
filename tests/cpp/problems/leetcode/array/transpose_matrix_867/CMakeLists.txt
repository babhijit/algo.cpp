project(algo.cpp.tests.cpp.problems.leetcode.array.transpose_matrix_867)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(TEST_BINARY transpose_matrix_867_tests)

add_executable(${TEST_BINARY} transpose_matrix_867_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.transpose_matrix_867
)

gtest_discover_tests(${TEST_BINARY})
