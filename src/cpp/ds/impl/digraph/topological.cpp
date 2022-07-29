#include "topological.hpp"

#include "directed_cycle.hpp"
#include "depth_first_order.hpp"

namespace algo::cpp::ds {

    Topological::Topological(const Digraph &G) {
        DirectedCycle directed_cycle = DirectedCycle(G);
        if (!directed_cycle.has_cycle()) {
            DepthFirstOrder depth_first_order = DepthFirstOrder(G);
            order_ = depth_first_order.reverse_post();
        }
    }

    bool Topological::is_DAG() const {
        return !order_.empty();
    }

    std::vector<int> Topological::order() const {
        return order_;
    }
}