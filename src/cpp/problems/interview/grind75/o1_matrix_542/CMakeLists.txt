project(algo.cpp.interview.grind75.o1_matrix_542)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/update_matrix.hpp update_matrix.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)