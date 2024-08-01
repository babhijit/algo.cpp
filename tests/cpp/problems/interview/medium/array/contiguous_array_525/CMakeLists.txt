project(algo.cpp.tests.interview.medium.contiguous_array_525)

set(PROJECT_BINARY test_algo_medium_contiguous_array_525_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        contiguous_array_test.cpp
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
        algo.interview.medium.array.contiguous_array_525
)

gtest_discover_tests(${PROJECT_BINARY})
