#include <filesystem>

#include "graph_loader_utils.hpp"

namespace algo::cpp::ds::tests::utils {

    std::filesystem::path get_problems_resource_path(const std::string &problem_name,
                                                     const std::string &source,
                                                     const std::string &category,
                                                     const std::string &file_name) {
        namespace fs = std::filesystem;
        auto path = fs::current_path();

        path /= "tests";
        path /= "resources";
        path /= "problems";
        path /= source;
        path /= category;
        path /= problem_name;
        path /= file_name;

        return path;
    }
}
