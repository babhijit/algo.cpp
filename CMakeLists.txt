cmake_minimum_required(VERSION 3.22)
project(algo.cpp)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR}, fmt::fmt)

add_subdirectory(src)
add_subdirectory(tests)