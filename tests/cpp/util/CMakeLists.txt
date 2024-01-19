project(algo.cpp.tests.util)

find_package(Boost COMPONENTS json REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(RES_HEADERS
        include/res/stl_compare_utils.hpp
        include/res/ds_resource_utils.hpp
        include/res/loader_utils.hpp
        include/res/test_resource_utils.hpp
        include/res/graph_loader_utils.hpp
        include/res/json/mapper/mapper.hpp
        include/res/json/json_parser.hpp
        include/res/json/mapper/bst_mapper.hpp
        )

set(RES_SOURCES
        impl/res/graph_loader_utils.cpp
        impl/res/loader_utils.cpp
        impl/res/ds_loader_utils.cpp
        impl/res/test_resource_utils.cpp
        )

set(LOADER_HEADERS
        include/loader/base_loader.hpp
        include/loader/json_loader.hpp
        include/loader/bst/load_bst.hpp
        include/loader/arrays/load_int_array.hpp
        )

set(LOADER_SOURCES impl/loader/base_loader.cpp
        impl/loader/json_loader.cpp
        impl/loader/bst/load_bst.cpp
        impl/loader/arrays/load_int_array.cpp)

set(DS_HEADERS include/ds/tree_node.hpp)

set(TEST_UTIL_HEADERS ${RES_HEADERS} ${LOADER_HEADERS} ${DS_HEADERS})

set(TEST_UTIL_SOURCES ${RES_SOURCES} ${LOADER_SOURCES} impl/loader/list/load_int_list.cpp include/loader/list/load_int_list.hpp)

include_directories(
        include
        include/loader
        include/loader/bst
        include/loader/list
        include/loader/arrays
        include/res
        include/res/json)

add_library(${PROJECT_NAME} STATIC ${TEST_UTIL_HEADERS} ${TEST_UTIL_SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
        algo.cpp.problems.leetcode.ds.tree.bst)

target_include_directories(${PROJECT_NAME} PUBLIC include)