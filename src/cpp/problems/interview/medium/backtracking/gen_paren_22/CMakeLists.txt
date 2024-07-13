project(algo.cpp.problems.interview.medium.backtracking.gen_paren_22)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/gen_parentheses.hpp gen_parentheses.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)