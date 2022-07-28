
#include "cc.hpp"


namespace algo::cpp::ds {

    CC::CC(const Graph& G) : marked_(G.V(), false), id_(G.V(), 0) {
        for (int v = 0; v < G.V(); ++v) {
            if (!marked_[v]) {
                dfs(G, v);
                ++count_;
            }
        }
    }

    void CC::dfs(const Graph& G, int v) {
        marked_[v] = true;
        id_[v] = count_;

        for (auto& w: G.adj(v)) {
            if (!marked_[w]) {
                dfs(G, w);
            }
        }
    }

    bool CC::connected(const int& v, const int& w) const {
        return id(v) == id(w);
    }

    std::vector<std::list<int>> CC::components() const {
        std::vector<std::list<int>> components(count_, std::list<int>());

        for (int v = 0; v < id_.size(); ++v) {
            components[id_[v]].push_back(v);
        }

        return components;
    }
}