#ifndef ALGO_CPP_GRAPH_LOADER_UTILS_HPP
#define ALGO_CPP_DS_LOADER_UTILS_HPP

#include <filesystem>
#include <string>

#include "ds/tree_node.hpp"

namespace algo::cpp::ds::tests::utils {

    std::filesystem::path get_problems_resource_path(const std::string &problem_name,
                                                     const std::string &source,
                                                     const std::string &category,
                                                     const std::string &file_name);
}

#endif //ALGO_CPP_GRAPH_LOADER_UTILS_HPP
