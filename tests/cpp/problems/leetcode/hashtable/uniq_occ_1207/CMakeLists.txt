project(algo.cpp.tests.cpp.problems.leetcode.hashtable.uniq_occ_1207)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(uniq_occ_1207_tests uniq_occ_1207_tests.cpp)

target_link_libraries(
        uniq_occ_1207_tests
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.hashtable.uniq_occ_1207
)

gtest_discover_tests(uniq_occ_1207_tests)