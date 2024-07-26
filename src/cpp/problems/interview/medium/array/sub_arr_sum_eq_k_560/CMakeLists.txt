project(algo.cpp.interview.medium.sub_arr_sum_eq_k_560)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/sub_array_sums.hpp sub_array_sums.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)