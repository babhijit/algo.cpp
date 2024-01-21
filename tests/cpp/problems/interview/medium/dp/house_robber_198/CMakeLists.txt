project(algo.cpp.tests.interview.medium.dp.house_robber_198)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY dp_house_robber_198)

add_executable(${PROJECT_BINARY} test_case.hpp dp_house_robber_198_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.problems.interview.medium.dp.house_robber_198
)

gtest_discover_tests(${PROJECT_BINARY})
