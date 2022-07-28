project(algo.cpp.test.cpp.ds.graph)

set(TEST_SOURCES    bag_tests.cpp
                    graph_test_utils.hpp
                    graph_test_utils.cpp
                    graph_tests.cpp
                    graph_from_file_tests.cpp
                    load_graphs_from_files_tests.cpp
                    dfs_tests.cpp
                    depth_first_paths_tests.cpp
        breadth_first_paths_tests.cpp)

add_executable(ds_graph_tests ${TEST_SOURCES})

target_link_libraries(
        ds_graph_tests
        GTest::gtest_main
        algo.cpp.tests.util
        algo.cpp.ds
)

gtest_discover_tests(ds_graph_tests)
