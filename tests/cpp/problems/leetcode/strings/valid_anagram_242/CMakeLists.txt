project(algo.cpp.tests.cpp.problems.leetcode.strings.valid_anagram_242)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY valid_anagram_242_tests)

add_executable(${PROJECT_BINARY} test_case.hpp valid_anagram_242_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.strings.valid_anagram_242
)

gtest_discover_tests(${PROJECT_BINARY})
