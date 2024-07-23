project(algo.cpp.tests.interview.medium.find_peak_element_162)

set(PROJECT_BINARY test_algo_medium_find_peak_element_162_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        find_peak_element_test.cpp
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
        algo.cpp.interview.medium.find_peak_element_162
)

gtest_discover_tests(${PROJECT_BINARY})
