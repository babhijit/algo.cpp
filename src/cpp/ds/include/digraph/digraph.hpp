#ifndef ALGO_CPP_DIGRAPH_HPP
#define ALGO_CPP_DIGRAPH_HPP


#include <iterator>
#include <vector>
#include <string>

#include "sequence/bag.hpp"

namespace algo::cpp::ds {

    class Digraph {
    private:
        const int V_;
        int E_ = 0;

        std::vector<Bag<int>> adj_;
    public:
        explicit Digraph(int V);

        int V() const { return V_; }

        int E() const { return E_; }

        void add_edge(int v, int w);

        Bag<int> adj(int v) const;

        std::string str() const;

    private:
        void validate_vertex(int v) const;
    };

}


#endif // #ifndef ALGO_CPP_DIGRAPH_HPP