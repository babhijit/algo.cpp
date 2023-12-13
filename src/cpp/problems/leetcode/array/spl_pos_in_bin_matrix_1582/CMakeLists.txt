project(algo.cpp.problems.leetcode.array.spl_pos_in_bin_matrix_1582)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/spl_pos_in_bin_matrix.hpp  spl_pos_in_bin_matrix.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)