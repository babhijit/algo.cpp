cmake_minimum_required(VERSION 3.22)
project(algo.cpp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)