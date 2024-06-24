project(algo.cpp.problems.leetcode.array.grumpy_bookstore_owner_1052)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/grumpy_bookstore_owner.hpp grumpy_bookstore_owner.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)