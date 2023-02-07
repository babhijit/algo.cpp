project(algo.cpp.tests.cpp.problems.leetcode.graph.all_paths_from_src_to_tgt_797)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY all_paths_from_src_to_tgt_797_tests)

add_executable(${PROJECT_BINARY} all_paths_from_src_to_tgt_797_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.problems.leetcode.graph.all_paths_from_src_to_tgt_797
)

gtest_discover_tests(${PROJECT_BINARY})
