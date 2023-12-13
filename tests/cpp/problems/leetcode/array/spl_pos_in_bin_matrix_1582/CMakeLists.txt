project(algo.cpp.tests.cpp.problems.leetcode.array.spl_pos_in_bin_matrix_1582)

set(TEST_BINARY spl_pos_in_bin_matrix_1582_tests)

add_executable(${TEST_BINARY}
        test_case.hpp
        spl_pos_in_bin_matrix_1582_tests.cpp)

target_link_libraries(${PROJECT_BINARY}
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.spl_pos_in_bin_matrix_1582)

gtest_discover_tests(${TEST_BINARY})