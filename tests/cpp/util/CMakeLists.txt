project(algo.cpp.tests.util)

add_library(${PROJECT_NAME} INTERFACE)

set(TEST_UTIL_SOURCES stl_compare_utils.hpp)

target_sources(${PROJECT_NAME} INTERFACE ${TEST_UTIL_SOURCES})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})