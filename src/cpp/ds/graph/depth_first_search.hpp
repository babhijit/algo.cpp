//
// Created by abhijit on 27/7/22.
//

#ifndef ALGO_CPP_DEPTH_FIRST_SEARCH_HPP
#define ALGO_CPP_DEPTH_FIRST_SEARCH_HPP

#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    template <typename T>
    class DepthFirstSearch {

    private:
        std::vector<bool> marked_;
        std::size_t count_ = 0;

    public:
        explicit DepthFirstSearch(const Graph<T> G, int s) : marked_(G.V(), false) {
            dfs(G, s);
        }

        bool marked(int v) const { return marked_[v]; }

        int count() const { return count_; }

    private:
        void dfs(const Graph<T> G, int v) {
            marked_[v] = true;
            ++count_;

            auto& adj = G.adj(v);
            for(auto it = adj.begin(); it != adj.end(); ++it) {
                int w = *it;
                if (!marked_[w]) {
                    dfs(G, w);
                }
            }
        }
    };

}

#endif //ALGO_CPP_DEPTH_FIRST_SEARCH_HPP
