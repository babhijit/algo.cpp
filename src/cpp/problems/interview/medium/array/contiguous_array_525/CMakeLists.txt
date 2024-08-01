project(algo.interview.medium.array.contiguous_array_525)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/contiguous_array.hpp contiguous_array.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)