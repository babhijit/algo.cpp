project(algo.cpp.tests.cpp.problems.leetcode.array.search_in_rotated_array_81)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(search_in_rotated_array_81_tests search_in_rotated_array_81_tests.cpp)

target_link_libraries(
        search_in_rotated_array_81_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.search_in_rotated_array_81
)

gtest_discover_tests(search_in_rotated_array_81_tests)
