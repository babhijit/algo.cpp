project(algo.cpp.tests.util)

set(TEST_UTIL_HEADERS
        include/stl_compare_utils.hpp
        include/ds_resource_utils.hpp include/ds_loader_utils.hpp)

set(TEST_UTIL_SOURCES impl/graph_test_utils.cpp impl/ds_loader_utils.cpp)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${TEST_UTIL_HEADERS} ${TEST_UTIL_SOURCES})

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)