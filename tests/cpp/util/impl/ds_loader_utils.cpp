#include "ds_loader_utils.hpp"

#include <filesystem>

#include <utils/graph_loader.hpp>

#include "ds_resource_utils.hpp"

namespace algo::cpp::ds::tests::utils {

    Graph load_graph(const std::string& filename) {
        std::filesystem::path filepath = get_graph_resource_path(filename);
        algo::cpp::ds::utils::GraphLoader<Graph> loader;
        return loader(filepath);
    }

    Digraph load_digraph(const std::string& filename) {
        std::filesystem::path filepath = get_digraph_resource_path(filename);
        algo::cpp::ds::utils::GraphLoader<Digraph> loader;
        return loader(filepath);
    }

}
