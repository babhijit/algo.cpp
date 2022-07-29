#include "ds_resource_utils.hpp"

namespace algo::cpp::ds::tests::utils {

    std::filesystem::path get_ds_resource_path(const std::string &file_name, const std::string &ds_type) {
        namespace fs = std::filesystem;
        auto path = fs::current_path();

        path /= "tests";
        path /= "resources";
        path /= "ds";
        path /= ds_type;
        path /= file_name;

        return path;
    }

    std::filesystem::path get_graph_resource_path(const std::string &file_name) {
        return get_ds_resource_path(file_name, "graph");
    }

    std::filesystem::path get_digraph_resource_path(const std::string &file_name) {
        return get_ds_resource_path(file_name, "digraph");
    }

}