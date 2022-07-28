
#include <cycle.hpp>

namespace algo::cpp::ds {

    Cycle::Cycle(const Graph &G) : marked_(G.V(), false) {

        for (int v = 0; v < G.V(); ++v) {
            if (!marked_[v]) {
                dfs(G, v, v);
            }
        }
    }

    void Cycle::dfs(const Graph& G, int v, int u) {
        marked_[v] = true;

        for (auto& w: G.adj(v)) {
            if (!marked_[w]) {
                dfs(G, w, v);
            } else if (w != u) {
                cycle_ = true;
            }
        }
    }
}