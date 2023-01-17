#ifndef ALGO_CPP_TEST_RESOURCE_UTILS_HPP
#define ALGO_CPP_TEST_RESOURCE_UTILS_HPP

#include <filesystem>

namespace algo::cpp::ds::tests::utils {

    std::filesystem::path get_test_resource_dir(const std::string &problem_source);


    std::filesystem::path get_test_resource_path(const std::string &problem_source,
                                                 const std::string &problem_name,
                                                 const std::string &file_name);
}

#endif //ALGO_CPP_TEST_RESOURCE_UTILS_HPP
