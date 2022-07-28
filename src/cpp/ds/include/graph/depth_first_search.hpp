//
// Created by abhijit on 27/7/22.
//

#ifndef ALGO_CPP_DEPTH_FIRST_SEARCH_HPP
#define ALGO_CPP_DEPTH_FIRST_SEARCH_HPP

#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    class DepthFirstSearch {

    private:
        std::vector<bool> marked_;
        std::size_t count_ = 0;

    public:
        explicit DepthFirstSearch(const Graph &G, int s);

        bool marked(int v) const { return marked_[v]; }

        int count() const { return count_; }

    private:
        void dfs(const Graph &G, int v);
    };

}

#endif //ALGO_CPP_DEPTH_FIRST_SEARCH_HPP
