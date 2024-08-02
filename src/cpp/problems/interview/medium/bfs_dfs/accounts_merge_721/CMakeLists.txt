project(algo.interview.medium.bfs_dfs.accounts_merge_721)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/acc_merge.hpp acc_merge.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)