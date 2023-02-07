project(algo.cpp.problems.leetcode.graph.all_paths_from_src_to_tgt_797)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/all_paths_from_src_to_tgt.hpp all_paths_from_src_to_tgt.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)