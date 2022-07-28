#ifndef ALGO_CPP_CC_HPP
#define ALGO_CPP_CC_HPP

#include <list>
#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    /**
     * Connected Components
     */
    class CC {
    private:
        std::vector<bool> marked_;

        std::vector<int> id_;

        std::size_t count_ = 0;

    public:
        CC(const Graph& G);

        bool connected(const int& v, const int& w) const;

        std::size_t id(const int& v) const { return id_[v]; }

        std::size_t count() const { return count_; }

        std::vector<std::list<int>> components() const;

    private:
        void dfs(const Graph& G, int v);
    };

}

#endif //ALGO_CPP_CC_HPP
