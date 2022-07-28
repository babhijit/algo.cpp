#include "graph_test_utils.hpp"

std::filesystem::path get_graph_resource_path(const std::string& file_name) {
    namespace fs = std::filesystem;
    auto path = fs::current_path();

    path /= "tests";
    path /= "resources";
    path /= "ds";
    path /= "graph";
    path /= file_name;

    return path;
}
