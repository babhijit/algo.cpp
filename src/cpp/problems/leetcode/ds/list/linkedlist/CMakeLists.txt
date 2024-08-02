project(algo.cpp.problems.leetcode.ds.list.linkedlist)

include_directories(include)

set(slist include/list_node.hpp list_node.cpp)
set(dlist include/dlist_node.hpp dlist_node.cpp)


add_library(${PROJECT_NAME} STATIC ${slist} ${dlist})

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)