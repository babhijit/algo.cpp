project(algo.cpp.problems.leetcode.strings.equivalent_strings_1662)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/equivalent_strings.hpp equivalent_strings.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
)

target_include_directories(${PROJECT_NAME} PUBLIC include)