project(algo.cpp.interview.grind75.max_sub_array_53)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/max_subarray.hpp max_subarray.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)