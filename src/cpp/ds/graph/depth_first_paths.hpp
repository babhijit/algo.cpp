#ifndef ALGO_CPP_DEPTH_FIRST_PATHS_HPP
#define ALGO_CPP_DEPTH_FIRST_PATHS_HPP

#include <list>
#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    template<typename T>
    class DepthFirstPaths {
    private:
        std::vector<bool> marked_;
        std::vector<int>  edge_to_;
        const int s_;

    public:
        explicit DepthFirstPaths(const Graph<T>& G, int source) : marked_(G.V(), false),
                                                                  edge_to_(G.V(), -1),
                                                                  s_(source) {
            edge_to_[source] = source;
            dfs(G, s_);
        }

        bool has_path_to(const int& v) const { return marked_[v]; }

        std::list<int> path_to(const int& v) const {
            std::list<int> path;

            if (has_path_to(v)) {
                for (int x = v; x != s_; x = edge_to_[x])
                    path.push_front(x);
                path.push_front(s_);
            }
            return path;
        }

    private:
        void dfs(const Graph<T>& G, int v) {
            marked_[v] = true;

            for (auto& w: G.adj(v)) {
                if(!marked_[w]) {
                    edge_to_[w] = v;
                    dfs(G, w);
                }
            }
        }
    };

}

#endif //ALGO_CPP_DEPTH_FIRST_PATHS_HPP