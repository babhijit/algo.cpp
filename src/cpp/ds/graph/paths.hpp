//
// Created by abhijit on 27/7/22.
//

#ifndef ALGO_CPP_PATHS_HPP
#define ALGO_CPP_PATHS_HPP

#include <list>
#include <vector>


#include "graph.hpp"

namespace algo::cpp::ds {

    template<typename T>
    class Paths {
    private:
        std::vector<bool> marked_;
        std::vector<int> edge_to_;
        const int s_;

    public:
        explicit Paths(const Graph<T> G, int s) : s_(s), marked_(G.V(), false), edge_to_(G.E(), -1) {
            dfs(G, s);
        }

        bool has_path_to(int v) {
            return marked_[v];
        }

        auto path_to(int v) {
            auto path = std::list<int>();

            for (int x = v; x != s_; x = edge_to_[x]) {
                path.push_front(x);
            }
            path.push_front(s_);

            return path;
        }

    private:
        void dfs(const Graph<T> G, int v) {
            marked_[v] = true;

            auto &adj = G.adj(v);
            for (auto it = adj.begin(); it != adj.end(); ++it) {
                int w = *it;
                if (!marked_[w]) {
                    edge_to_[w] = v;
                    dfs(G, w);
                }
            }
        }
    };

}

#endif //ALGO_CPP_PATHS_HPP
