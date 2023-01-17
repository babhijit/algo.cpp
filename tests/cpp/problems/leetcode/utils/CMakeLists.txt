project(algo.cpp.tests.leetcode.utils)

include_directories(include)

set(TEST_UTIL_HEADERS include/file_utils.hpp)
set(TEST_UTIL_SOURCES impl/file_utils.cpp)


add_library(${PROJECT_NAME} STATIC ${TEST_UTIL_HEADERS} ${TEST_UTIL_SOURCES})

target_link_libraries(${PROJECT_NAME} algo.cpp.tests.util)
