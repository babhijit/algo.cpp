cmake_minimum_required(VERSION 3.22)
project(algo.cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/cpp/ds)

add_subdirectory(src)
add_subdirectory(tests)