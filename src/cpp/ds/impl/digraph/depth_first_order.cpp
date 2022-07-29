#include "depth_first_order.hpp"

namespace algo::cpp::ds {

    DepthFirstOrder::DepthFirstOrder(const Digraph &G) : marked_(G.V(), false) {
        for (int v = 0; v < G.V(); ++v) {
            if (!marked_[v]) {
                dfs(G, v);
            }
        }
    }

    void DepthFirstOrder::dfs(const Digraph &G, int v) {
        marked_[v] = true;

        pre_.push_back(v);

        for (auto &w: G.adj(v)) {
            if (!marked_[w]) {
                dfs(G, w);
            }
        }

        post_.push_back(v);
        reverse_post_.push_front(v);
    }

    std::vector<int> DepthFirstOrder::pre() const {
        return {std::begin(pre_), std::end(pre_)};
    }

    std::vector<int> DepthFirstOrder::post() const {
        return {std::begin(post_), std::end(post_)};
    }

    std::vector<int> DepthFirstOrder::reverse_post() const {
        return {std::begin(reverse_post_), std::end(reverse_post_)};
    }
}