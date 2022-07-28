#ifndef ALGO_CPP_DEPTH_FIRST_PATHS_HPP
#define ALGO_CPP_DEPTH_FIRST_PATHS_HPP

#include <list>
#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    class DepthFirstPaths {
    private:
        std::vector<bool> marked_;
        std::vector<int> edge_to_;
        const int s_;

    public:
        explicit DepthFirstPaths(const Graph &G, int source);

        bool has_path_to(const int &v) const { return marked_[v]; }

        std::list<int> path_to(const int &v) const;

    private:
        void dfs(const Graph &G, int v);
    };

}

#endif //ALGO_CPP_DEPTH_FIRST_PATHS_HPP