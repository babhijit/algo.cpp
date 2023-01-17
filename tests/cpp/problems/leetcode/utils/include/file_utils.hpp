#ifndef ALGO_CPP_TESTS_LEETCODE_FILE_UTILS_HPP
#define ALGO_CPP_TESTS_LEETCODE_FILE_UTILS_HPP

#include <filesystem>

namespace algo::cpp::ds::tests::utils::leetcode {
    std::filesystem::path get_test_leetcode_dir();

    std::filesystem::path get_test_ds_dir(const std::string &ds_type);

}

#endif //ALGO_CPP_TESTS_LEETCODE_FILE_UTILS_HPP
