#include "two_color.hpp"


namespace algo::cpp::ds {

    TwoColor::TwoColor(const Graph& G) : marked_(G.V(), false), color_(G.V(), false) {
        for (int v = 0; v < G.V(); ++v ) {
            if (!marked_[v]) {
                dfs(G, v);
            }
        }
    }

    void TwoColor::dfs(const Graph& G, int v) {
        marked_[v] = true;

        for (auto& w: G.adj(v)) {
            if(!marked_[w]) {
                color_[w] = !color_[v];
                dfs(G, w);
            } else if (color_[v] == color_[w]) {
                is_bipartite_ = false;
            }
        }
    }
}