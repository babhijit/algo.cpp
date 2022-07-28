#include "depth_first_search.hpp"

namespace algo::cpp::ds {

    DepthFirstSearch::DepthFirstSearch(const Graph &G, int s) : marked_(G.V(), false) {
        dfs(G, s);
    }

    void DepthFirstSearch::dfs(const Graph &G, int v) {
        marked_[v] = true;
        ++count_;

        auto &adj = G.adj(v);
        for (auto w: adj) {
            if (!marked_[w]) {
                dfs(G, w);
            }
        }
    }
}
