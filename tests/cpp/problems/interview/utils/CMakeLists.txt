project(algo.cpp.tests.cpp.problems.interview.utils)

include_directories(include)

set(TEST_UTIL_HEADERS include/iview_file_utils.hpp)
set(TEST_UTIL_SOURCES impl/iview_file_utils.cpp)


add_library(${PROJECT_NAME} STATIC ${TEST_UTIL_HEADERS} ${TEST_UTIL_SOURCES})

target_link_libraries(${PROJECT_NAME} algo.cpp.tests.util)

target_include_directories(${PROJECT_NAME} PUBLIC include)
