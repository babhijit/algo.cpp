project(algo.cpp.tests.interview.medium.diag_traverse_498)

set(PROJECT_BINARY test_algo_medium_diag_traverse_498_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        diag_traverse_498_test.cpp
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
        algo.cpp.interview.medium.diag_traverse_498
)

gtest_discover_tests(${PROJECT_BINARY})
