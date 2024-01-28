project(algo.cpp.tests.cpp.problems.leetcode.array.out_of_boundary_paths_576)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY out_of_boundary_paths_576_tests)

add_executable(${PROJECT_BINARY} test_case.hpp out_of_boundary_paths_576_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.out_of_boundary_paths_576
)

gtest_discover_tests(${PROJECT_BINARY})
