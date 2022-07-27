#ifndef ALGO_CPP_GRAPH_HPP
#define ALGO_CPP_GRAPH_HPP

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "bag.hpp"

namespace algo::cpp::ds {

    template<typename T>
    class Graph {
    private:
        // Number of V_
        int V_;

        // number of E_
        int E_;

        // adjacency list
        std::vector<Bag<T>> adj_;

    public:
        explicit Graph(const int V) {
            if (V < 0)  throw std::invalid_argument("V must be positive");
            V_ = V;
            E_ = 0;
            adj_ = std::vector<Bag<T>>(V_, Bag<T>());
        }

        explicit Graph(std::ifstream& in) {
            in >> V_;
            if (V_ < 0)  throw std::invalid_argument("Number of Vertices in a Graph must be positive");

            adj_ = std::vector<Bag<T>>(V_, Bag<T>());

            int E;
            in >> E;
            if (E < 0)   throw std::invalid_argument("Number of Edges in a Graph must be positive");

            E_ = 0;
            int v, w;
            for (int e = 0; e < E; ++e) {
                in >> v >> w;
                add_edge(v, w);
            }
        }

        Graph(const Graph& G) : V_(G.V()) {
            E_ = G.E();

            for (int v = 0; v < V_; ++v) {
                // add the E_ in reverse so that both the adjacency lists are in the same order
                auto& adj = G.adj(v);
                auto& bag = adj_[v];
                for (auto it = adj.rbegin(); it != adj.rend(); ++it) {
                    bag.add(*it);
                }
            }
        }

        Graph(Graph&& G)  noexcept {
            V_ = G.V_;
            E_ = G.E_;
            adj_ = std::move(G.adj_);
        }

        int V() const { return V_; }

        int E() const { return E_; }

        void add_edge(int v, int w) {
            validate_vertex(v);
            validate_vertex(w);

            ++E_;
            adj_[v].add(w);
            adj_[w].add(v);
        }

        const Bag<T>& adj(int v) const {
            validate_vertex(v);
            return adj_[v];
        }

        std::size_t degree(int v) const {
            validate_vertex(v);
            return adj_[v].size();
        }

        std::size_t self_loops_count() const {
            std::size_t count = 0;

            for (int v = 0; v < V_; ++v) {
                auto &adj = adj_[v];
                for (auto it = adj.begin(); it != adj.end(); ++it) {
                    int w = *it;
                    if (w == v) {
                        ++count;
                    }
                }
            }

            // in undirected graph, each edge is counted twice
            return count/2;
        }

        std::size_t max_degree() const {
            std::size_t max_degree = 0;
            for (int v = 0; v < V_; ++v) {
                max_degree = std::max(max_degree, degree(v));
            }
            return max_degree;
        }

        std::string str() const {
            std::ostringstream oss;
            oss << V_ << " V_, " << E_ << " E_";
            for (int v = 0; v < V_; ++v) {
                oss << "\n" << v << ": ";
                for (auto& w: adj_[v]) {
                    oss << w << " ";
                }
            }
            oss << std::endl;
            return oss.str();
        }

    private:

        void validate_vertex(int v) const {
            if ((v < 0) || (v >= V_))
                throw std::invalid_argument(std::string("v must be between 0 and ") + std::to_string(V_));
        }
    };

}

#endif //ALGO_CPP_GRAPH_HPP
