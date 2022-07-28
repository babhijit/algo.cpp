#include "depth_first_paths.hpp"

namespace algo::cpp::ds {

    DepthFirstPaths::DepthFirstPaths(const Graph &G, int source) : marked_(G.V(), false),
                                                                   edge_to_(G.V(), -1),
                                                                   s_(source) {
        edge_to_[source] = source;
        dfs(G, s_);
    }

    std::list<int> DepthFirstPaths::path_to(const int &v) const {
        std::list<int> path;

        if (has_path_to(v)) {
            for (int x = v; x != s_; x = edge_to_[x])
                path.push_front(x);
            path.push_front(s_);
        }
        return path;
    }

    void DepthFirstPaths::dfs(const Graph &G, int v) {
        marked_[v] = true;

        for (auto &w: G.adj(v)) {
            if (!marked_[w]) {
                edge_to_[w] = v;
                dfs(G, w);
            }
        }
    }
}
