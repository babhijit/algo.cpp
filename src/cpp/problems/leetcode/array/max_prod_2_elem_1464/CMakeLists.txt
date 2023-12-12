project(algo.cpp.problems.leetcode.array.max_prod_2_elem_1464)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/max_product.hpp max_product.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)
