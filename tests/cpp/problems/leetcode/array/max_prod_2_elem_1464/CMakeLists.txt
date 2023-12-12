project(algo.cpp.tests.cpp.problems.leetcode.array.max_prod_2_elem_1464)

set(TEST_BINARY max_prod_2_elem_1464_tests)

add_executable(${TEST_BINARY} max_prod_2_elem_1464_tests.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.max_prod_2_elem_1464
)

gtest_discover_tests(${TEST_BINARY})
