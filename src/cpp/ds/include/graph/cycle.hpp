#ifndef ALGO_CPP_CYCLE_HPP
#define ALGO_CPP_CYCLE_HPP

#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    class Cycle {
    private:
        std::vector<bool> marked_;
        bool cycle_ = false;
    public:
        explicit Cycle(const Graph& G);

        bool has_cycle() const { return cycle_; }

    private:
        void dfs(const Graph& G, int v, int u);
    };
}

#endif //ALGO_CPP_CYCLE_HPP
