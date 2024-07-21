project(algo.cpp.tests.cpp)

add_executable(algo_cpp_tests sanity_test.cpp)

target_link_libraries(
        algo_cpp_tests
        GTest::gtest_main
)

gtest_discover_tests(algo_cpp_tests)

add_subdirectory(util)
add_subdirectory(ds)
add_subdirectory(problems)


add_custom_command(
        TARGET algo_cpp_tests
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)

