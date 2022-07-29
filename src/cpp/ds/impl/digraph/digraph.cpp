#include <digraph.hpp>

#include <sstream>
#include <stdexcept>

namespace algo::cpp::ds {

    Digraph::Digraph(int V) : V_(V) {
        if (V < 0) throw std::invalid_argument("V must be positive");
        adj_ = std::vector<Bag<int>>(V_, Bag<int>());
    }

    void Digraph::add_edge(int v, int w) {
        validate_vertex(v);
        validate_vertex(w);

        adj_[v].add(w);
        ++E_;
    }

    Bag<int> Digraph::adj(int v) const {
        validate_vertex(v);

        return adj_[v];
    }

    void Digraph::validate_vertex(int v) const {
        if (v < 0 || v >= V_) {
            throw std::invalid_argument(std::string("v must be between 0 and ") + std::to_string(V_ - 1));
        }
    }

    std::string Digraph::str() const {
        std::ostringstream oss;
        for (int v = 0; v < V_; ++v) {
            oss << v << ": [";
            for (auto& w: adj_[v]) {
                oss << w << " ";
            }
            oss << "]\n";
        }
        return oss.str();
    }
}