//
// Created by abhijit on 29/7/22.
//

#ifndef ALGO_CPP_DIRECTED_CYCLE_HPP
#define ALGO_CPP_DIRECTED_CYCLE_HPP

#include <list>
#include <vector>

#include "digraph.hpp"

namespace algo::cpp::ds {

    class DirectedCycle {
    public:
        explicit DirectedCycle(const Digraph &G);

        bool has_cycle() const;

        std::vector<int> cycle() const;

    private:
        void dfs(const Digraph &G, int v, std::vector<bool>& on_stack);

    private:
        std::vector<bool> marked_;
        std::vector<int> edge_to_;
        std::list<int> cycle_;
    };

} // ds

#endif //ALGO_CPP_DIRECTED_CYCLE_HPP
