project(algo.cpp.tests.cpp.problems.leetcode.array.min_time_visiting_all_points_1266_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})


add_executable(min_time_visiting_all_points_1266_tests
        min_time_visiting_all_points_1266_tests.cpp
        test_case.hpp
        )

target_link_libraries(
        min_time_visiting_all_points_1266_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.min_time_visiting_all_points_1266
)

gtest_discover_tests(min_time_visiting_all_points_1266_tests)

