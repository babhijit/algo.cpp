project(algo.cpp.tests.cpp.problems.interview.medium.tree.lowest_common_anscestor_236)

set(PROJECT_BINARY lowest_common_anscestor_236_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY} lowest_common_anscestor_236_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.ds.tree.bst
        algo.cpp.problems.interview.medium.tree.lowest_common_anscestor_236
)

gtest_discover_tests(${PROJECT_BINARY})
