project(algo.interview.medium.array.dot_product_2_sparse_vectors_1570)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/sparse_vector.hpp sparse_vector.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)