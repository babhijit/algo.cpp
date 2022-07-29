#ifndef ALGO_CPP_DS_LOADER_UTILS_HPP
#define ALGO_CPP_DS_LOADER_UTILS_HPP

#include <graph/graph.hpp>
#include <digraph/digraph.hpp>


namespace algo::cpp::ds::tests::utils {

    Graph load_graph(const std::string& filename);
    Digraph load_digraph(const std::string& filename);

}

#endif //ALGO_CPP_DS_LOADER_UTILS_HPP
