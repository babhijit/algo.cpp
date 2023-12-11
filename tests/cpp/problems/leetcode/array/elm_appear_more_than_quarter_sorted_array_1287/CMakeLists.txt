project(algo.cpp.tests.cpp.problems.leetcode.array.elm_appear_more_than_quarter_sorted_array_1287)

set(PROJECT_BINARY elm_appear_more_than_quarter_sorted_array_1287)

add_executable(${PROJECT_BINARY}
        test_case.hpp
        leetcode_elm_appear_more_than_quarter_sorted_array_tests.cpp)

target_link_libraries(${PROJECT_BINARY}
        ${TEST_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.elm_appear_more_than_quarter_sorted_array_1287)

gtest_discover_tests(${PROJECT_BINARY})