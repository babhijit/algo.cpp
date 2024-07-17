project(algo.cpp.interview.grind75.o1_matrix_542)

include_directories(include impl)

add_library(${PROJECT_NAME} STATIC
        include/update_matrix.hpp
        update_matrix.cpp
        impl/update_matrix_dp.hpp
        impl/update_matrix_bfs.hpp
)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)