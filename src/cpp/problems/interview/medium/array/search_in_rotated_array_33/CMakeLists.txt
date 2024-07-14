project(algo.cpp.interview.medium.search_in_rotated_array_33)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/search_in_rotated_array.hpp search_in_rotated_array.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)