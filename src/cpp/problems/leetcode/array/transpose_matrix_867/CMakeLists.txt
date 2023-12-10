project(algo.cpp.problems.leetcode.array.transpose_matrix_867)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/transpose_matrix.hpp transpose_matrix.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)