project(algo.cpp.problems.leetcode.strings.find_words_by_char_1160)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/find_words_by_char.hpp find_words_by_char.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
)

target_include_directories(${PROJECT_NAME} PUBLIC include)