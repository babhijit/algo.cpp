#ifndef ALGO_CPP_DEPTH_FIRST_ORDER_HPP
#define ALGO_CPP_DEPTH_FIRST_ORDER_HPP

#include <deque>
#include <vector>

#include "digraph.hpp"

namespace algo::cpp::ds {

    class DepthFirstOrder {
    public:
        explicit DepthFirstOrder(const Digraph &G);

        std::vector<int> pre() const;

        std::vector<int> post() const;

        std::vector<int> reverse_post() const;

    private:
        void dfs(const Digraph &G, int v);

    private:
        std::deque<int> pre_;
        std::deque<int> post_;
        std::deque<int> reverse_post_;
        std::vector<bool> marked_;
    };

}

#endif //ALGO_CPP_DEPTH_FIRST_ORDER_HPP
