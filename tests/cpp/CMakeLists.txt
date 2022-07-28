project(algo.cpp.tests.cpp)

add_executable(sanity_tests sanity_test.cpp)

target_link_libraries(
        sanity_tests
        GTest::gtest_main
)

gtest_discover_tests(sanity_tests)

add_subdirectory(ds)