#ifndef ALGO_CPP_TOPOLOGICAL_HPP
#define ALGO_CPP_TOPOLOGICAL_HPP

#include <vector>

#include "digraph.hpp"


namespace algo::cpp::ds {

    class Topological {
    public:
        explicit Topological(const Digraph& G);

        // Is G a DAG
        bool is_DAG() const;

        // Vertices in Topological Order
        std::vector<int> order() const;

    private:
        std::vector<int> order_;
    };

}

#endif //ALGO_CPP_TOPOLOGICAL_HPP
