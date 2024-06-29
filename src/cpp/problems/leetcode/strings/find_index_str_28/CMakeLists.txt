project(algo.cpp.problems.leetcode.strings.find_index_str_28)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/find_index_of_str.hpp find_index_of_str.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
)

target_include_directories(${PROJECT_NAME} PUBLIC include)