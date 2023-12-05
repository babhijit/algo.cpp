#include "test_resource_utils.hpp"

#include <filesystem>

namespace algo::cpp::ds::tests::utils {
    std::filesystem::path get_test_resource_dir(const std::string &problem_source,
                                                const std::string &category) {
        namespace fs = std::filesystem;
        auto path = fs::current_path();

        path /= "tests";
        path /= "resources";
        path /= category;
        path /= problem_source;

        return path;

    }

    std::filesystem::path get_test_ds_dir(const std::string &problem_source,
                                          const std::string &ds_type,
                                          const std::string &category) {
        auto resource_dir = get_test_resource_dir(problem_source, category);
        resource_dir /= ds_type;
        return resource_dir;
    }

    std::filesystem::path get_test_resource_path(const std::string &problem_source,
                                                 const std::string &ds_type,
                                                 const std::string &problem_name,
                                                 const std::string &file_name,
                                                 const std::string &category) {
        auto resource_dir = get_test_ds_dir(problem_source, ds_type, category);
        auto usecase_file = resource_dir / problem_name / file_name;
        return usecase_file;
    }

}