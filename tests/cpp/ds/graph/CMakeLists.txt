project(algo.cpp.test.cpp.ds.graph)

set(TEST_SOURCES    bag_tests.cpp
        ../../util/include/res/ds_resource_utils.hpp
        ../../util/impl/res/graph_loader_utils.cpp
                    graph_tests.cpp
                    graph_from_file_tests.cpp
                    load_graphs_from_files_tests.cpp
                    dfs_tests.cpp
                    depth_first_paths_tests.cpp
        breadth_first_paths_tests.cpp cc_tests.cpp cycle_tests.cpp two_colors_tests.cpp)

add_executable(ds_graph_tests ${TEST_SOURCES})

target_link_libraries(
        ds_graph_tests
        GTest::gtest_main
        algo.cpp.ds
        algo.cpp.tests.util
)

gtest_discover_tests(ds_graph_tests)
