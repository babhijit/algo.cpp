project(algo.cpp.tests.cpp.problems.leetcode.pq.k_largest_215)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(k_largest_215_tests k_largest_215_tests.cpp)

target_link_libraries(
        k_largest_215_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.pq.k_largest_215
)

gtest_discover_tests(k_largest_215_tests)
