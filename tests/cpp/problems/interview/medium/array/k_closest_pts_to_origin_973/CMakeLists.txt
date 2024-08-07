project(algo.cpp.tests.interview.medium.array.number_of_islands_200)

set(PROJECT_BINARY test_algo_medium_number_of_islands_200_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        number_of_islands_tests.cpp
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
        algo.cpp.interview.medium.array.number_of_islands_200
)

gtest_discover_tests(${PROJECT_BINARY})
