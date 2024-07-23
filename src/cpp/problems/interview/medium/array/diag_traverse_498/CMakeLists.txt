project(algo.cpp.interview.medium.diag_traverse_498)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/diag_traverse.hpp diag_traverse.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)