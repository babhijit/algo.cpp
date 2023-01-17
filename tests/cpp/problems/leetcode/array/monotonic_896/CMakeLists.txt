project(algo.cpp.tests.cpp.problems.leetcode.array.monotonic_896)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(monotonic_896_tests leetcode_monotonic_896_tests.cpp test_case.hpp)

target_link_libraries(
        monotonic_896_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.array.monotonic_896
)

gtest_discover_tests(monotonic_896_tests)
