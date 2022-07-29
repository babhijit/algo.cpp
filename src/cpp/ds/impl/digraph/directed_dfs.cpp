
#include "directed_dfs.hpp"

namespace algo::cpp::ds {

    DirectedDFS::DirectedDFS(const Digraph &G, int s) : marked_(G.V(), false) {
        dfs(G, s);
    }

    void DirectedDFS::dfs(const Digraph &G, int v) {
        marked_[v] = true;

        for (auto &w: G.adj(v)) {
            if (!marked_[w]) {
                dfs(G, w);
            }
        }
    }

    bool DirectedDFS::visited(int v) const {
        return marked_[v];
    }
}