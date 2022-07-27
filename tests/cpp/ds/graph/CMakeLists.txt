project(algo.cpp.test.cpp.ds.graph)

add_executable(ds_graph_tests bag_tests.cpp graph_tests.cpp)

target_link_libraries(
        ds_graph_tests
        GTest::gtest_main
        algo.cpp
)

gtest_discover_tests(ds_graph_tests)
