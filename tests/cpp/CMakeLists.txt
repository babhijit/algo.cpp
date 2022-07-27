project(algo.cpp.tests.cpp)

add_executable(sanity_test sanity_test.cpp)

target_link_libraries(
        sanity_test
        GTest::gtest_main
)

gtest_discover_tests(sanity_test)
#add_test(NAME sanity_test COMMAND sanity)

add_subdirectory(ds)