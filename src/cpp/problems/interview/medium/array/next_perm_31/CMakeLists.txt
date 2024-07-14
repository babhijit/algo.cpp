project(algo.cpp.interview.medium.next_perm_31)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/next_perm.hpp next_perm.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)