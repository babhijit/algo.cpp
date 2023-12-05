project(algo.cpp.tests.cpp.problems.leetcode.maths.count_matches_1688)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY count_matches_1688_tests)

add_executable(${PROJECT_BINARY} count_matches_1688_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.maths.count_matches_1688
)

gtest_discover_tests(${PROJECT_BINARY})
