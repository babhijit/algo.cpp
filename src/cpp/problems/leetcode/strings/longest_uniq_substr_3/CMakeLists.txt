project(algo.cpp.problems.leetcode.strings.longest_uniq_substr_3)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/longest_uniq_substr.hpp longest_uniq_substr.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)