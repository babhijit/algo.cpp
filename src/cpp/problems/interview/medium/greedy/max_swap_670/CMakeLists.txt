project(algo.cpp.problems.interview.medium.greedy.max_swap_670)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/max_swap.hpp max_swap.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)