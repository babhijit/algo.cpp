project(algo.cpp.tests.interview.medium.array.dot_product_2_sparse_vectors_1570)

set(PROJECT_BINARY test_algo_medium_dot_product_2_sparse_vectors_1570_tests)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        dot_product_sparse_vectors_test.cpp
)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.interview.medium.array.dot_product_2_sparse_vectors_1570
)

gtest_discover_tests(${PROJECT_BINARY})
