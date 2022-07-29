#include "directed_cycle.hpp"

namespace algo::cpp::ds {

    DirectedCycle::DirectedCycle(const Digraph &G) :
            marked_(G.V(), false),
            edge_to_(G.V(), false) {
        auto on_stack = std::vector<bool>(G.V(), false);

        for (int v = 0; !has_cycle() && (v < G.V()); ++v) {
            if (!marked_[v]) {
                dfs(G, v, on_stack);
            }
        }
    }

    void DirectedCycle::dfs(const Digraph &G, int v, std::vector<bool> &on_stack) {
        on_stack[v] = true;
        marked_[v] = true;

        for (auto &w: G.adj(v)) {
            if(has_cycle()) {
                break;
            }

            if(!marked_[w]) {
                edge_to_[w] = v;
                dfs(G, w, on_stack);
            } else if(on_stack[w]) {
                for (int x = v; x != w; x = edge_to_[x]) {
                    cycle_.push_front(x);
                }
                cycle_.push_front(w);
                cycle_.push_front(v);
            }
        }

        on_stack[v] = false;
    }

    bool DirectedCycle::has_cycle() const {
        return !cycle_.empty();
    }

    std::vector<int> DirectedCycle::cycle() const {
        return {std::begin(cycle_), std::end(cycle_)};
    }

} // ds