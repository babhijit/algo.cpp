#ifndef ALGO_CPP_DS_RESOURCE_UTILS_HPP
#define ALGO_CPP_DS_RESOURCE_UTILS_HPP

#include <filesystem>

namespace algo::cpp::ds::tests::utils {

    std::filesystem::path get_ds_resource_dir(const std::string &ds_type);

    std::filesystem::path get_ds_resource_path(const std::string &file_name, const std::string &ds_type);

    std::filesystem::path get_bst_resource_path(const std::string &file_name);

    std::filesystem::path get_graph_resource_path(const std::string &file_name);

    std::filesystem::path get_digraph_resource_path(const std::string &file_name);

}

#endif //ALGO_CPP_DS_RESOURCE_UTILS_HPP
