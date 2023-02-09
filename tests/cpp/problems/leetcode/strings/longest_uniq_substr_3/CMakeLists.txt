project(algo.cpp.tests.cpp.problems.leetcode.strings.longest_uniq_substr_3)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY longest_uniq_substr_3_tests)

add_executable(${PROJECT_BINARY} longest_uniq_substr_3_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.strings.longest_uniq_substr_3
)

gtest_discover_tests(${PROJECT_BINARY})
