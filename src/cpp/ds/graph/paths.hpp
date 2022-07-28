//
// Created by abhijit on 27/7/22.
//

#ifndef ALGO_CPP_PATHS_HPP
#define ALGO_CPP_PATHS_HPP

#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    template<typename T>
    class Paths {
    private:
        std::vector<bool> marked_;
        std::size_t count_ = 0;

    public:
        explicit Paths(const Graph<T>& G, int source) : marked_(G.V(), false) {
            dfs(G, source);
        }

        std::size_t count() const { return count_; }

        bool connected(int v) const { return marked_[v]; }

    private:
        void dfs(const Graph<T>& G, int v) {
            marked_[v] = true;
            ++count_;

            auto& adj = G.adj(v);
            for (auto it = std::begin(adj); it != std::end(adj); ++it) {
                int w = *it;
                if (!marked_[w]) {
                    dfs(G, w);
                }
            }
        }
    };

}

#endif //ALGO_CPP_PATHS_HPP
