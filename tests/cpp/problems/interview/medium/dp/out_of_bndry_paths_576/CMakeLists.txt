project(algo.cpp.tests.interview.medium.dp.out_of_boundary_paths_576)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY dp_out_of_boundary_paths_576_tests)

add_executable(${PROJECT_BINARY} test_case.hpp dp_out_of_boundary_paths_576_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.dp.out_of_boundary_paths_576
)

gtest_discover_tests(${PROJECT_BINARY})
