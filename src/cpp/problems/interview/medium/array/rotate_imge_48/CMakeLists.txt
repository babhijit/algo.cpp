project(algo.cpp.interview.medium.rotate_image_48)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/rotate_image.hpp rotate_image.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)