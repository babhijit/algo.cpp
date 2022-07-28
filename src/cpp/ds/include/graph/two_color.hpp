#ifndef ALGO_CPP_TWO_COLOR_HPP
#define ALGO_CPP_TWO_COLOR_HPP

#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    class TwoColor {
    private:
        std::vector<bool> marked_;
        std::vector<bool> color_;
        bool is_bipartite_ = true;

    public:
        explicit TwoColor(const Graph& G);

        bool is_bipartite() const { return is_bipartite_; }

    private:
        void dfs(const Graph&, int v);
    };

}

#endif //ALGO_CPP_TWO_COLOR_HPP
