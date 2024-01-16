#ifndef ALGO_CPP_TESTS_INTERVIEW_FILE_UTILS_HPP
#define ALGO_CPP_TESTS_INTERVIEW_FILE_UTILS_HPP

#include <filesystem>

namespace algo::cpp::ds::tests::utils::interview {
    std::filesystem::path get_test_interview_dir();

    std::filesystem::path get_test_ds_dir(const std::string &ds_type);

}

#endif //ALGO_CPP_TESTS_INTERVIEW_FILE_UTILS_HPP
