project(algo.cpp.interview.medium.nested_list_weighted_sum_339)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/nested_list_weighted_sum.hpp
        nested_list_weighted_sum.cpp
        include/nested_integer.hpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)