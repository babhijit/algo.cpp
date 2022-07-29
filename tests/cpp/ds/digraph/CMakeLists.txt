project(algo.cpp.test.cpp.ds.digraph)

set(TEST_SOURCES
        digraph_from_file_tests.cpp
        digraph_tests.cpp)

add_executable(ds_digraph_tests ${TEST_SOURCES})

target_link_libraries(
        ds_digraph_tests
        GTest::gtest_main
        algo.cpp.tests.util
        algo.cpp.ds
)

gtest_discover_tests(ds_digraph_tests)
