project(algo.cpp.test.cpp.ds.graph)

add_executable(bag_test bag_test.cpp)

target_link_libraries(
        bag_test
        GTest::gtest_main
        algo.cpp
)

add_test(NAME bag_test COMMAND sanity)