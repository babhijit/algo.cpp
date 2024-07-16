project(algo.cpp.interview.medium.find_first_last_position_in_sorted_array_34)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/range_search.hpp range_search.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)