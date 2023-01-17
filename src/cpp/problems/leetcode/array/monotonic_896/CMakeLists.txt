project(algo.cpp.problems.leetcode.array.monotonic_896)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/monotonic_array.hpp monotonic_array.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)