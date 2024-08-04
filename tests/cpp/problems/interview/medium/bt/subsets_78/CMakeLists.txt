project(algo.cpp.tests.problems.interview.medium.bt.subsets_78)

set(PROJECT_BINARY test_algo_medium_${PROJECT_NAME}_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        subsets_tests.cpp
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
        algo.cpp.problems.interview.medium.bt.subsets_78
)

gtest_discover_tests(${PROJECT_BINARY})
