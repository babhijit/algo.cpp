#ifndef ALGO_CPP_GRAPH_HPP
#define ALGO_CPP_GRAPH_HPP

#include <filesystem>
#include <vector>

#include "sequence/bag.hpp"

namespace algo::cpp::ds {

    class Graph {
    private:
        // Number of vertices
        const int V_;

        // number of E_
        int E_ = 0;

        // adjacency list
        std::vector<Bag<int>> adj_;

    public:
        explicit Graph(const int V);

        Graph(const Graph &G);

        Graph(Graph &&G) noexcept;

        int V() const;

        int E() const;

        void add_edge(int v, int w);

        const Bag<int> &adj(int v) const;

        std::size_t degree(int v) const;

        std::size_t self_loops_count() const;

        std::size_t max_degree() const;

        std::string str() const;

    private:

        void validate_vertex(int v) const;
    };
}

#endif //ALGO_CPP_GRAPH_HPP
