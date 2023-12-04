project(algo.cpp.tests.cpp.problems.leetcode.strings.largest_3_same_num_2264)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY largest_3_same_num_2264_tests)

add_executable(${PROJECT_BINARY} largest_3_same_num_2264_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.strings.largest_3_same_num_2264
)

gtest_discover_tests(${PROJECT_BINARY})
