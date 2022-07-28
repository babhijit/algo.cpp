#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <graph.hpp>

namespace algo::cpp::ds {

    Graph::Graph(const int V) : V_(V) {
        if (V < 0) throw std::invalid_argument("V must be positive");
        adj_ = std::vector<Bag<int>>(V_, Bag<int>());
    }

    Graph::Graph(const Graph &G) : V_(G.V()) {
        E_ = G.E();
        adj_ = std::vector<Bag<int>>(V_, Bag<int>());

        for (int v = 0; v < V_; ++v) {
            // add the E_ in reverse so that both the adjacency lists are in the same order
            auto &adj = G.adj(v);
            auto &bag = adj_[v];
            for (auto it = adj.rbegin(); it != adj.rend(); ++it) {
                bag.add(*it);
            }
        }
    }

    Graph::Graph(Graph &&G) noexcept: V_(G.V()) {
        E_ = G.E();
        adj_ = std::move(G.adj_);
    }

    int Graph::V() const { return V_; }

    int Graph::E() const { return E_; }

    void Graph::add_edge(int v, int w) {
        validate_vertex(v);
        validate_vertex(w);

        ++E_;
        adj_[v].add(w);
        adj_[w].add(v);
    }

    const Bag<int> &Graph::adj(int v) const {
        validate_vertex(v);
        validate_vertex(v);
        return adj_[v];
    }

    std::size_t Graph::degree(int v) const {
        validate_vertex(v);
        return adj_[v].size();
    }

    std::size_t Graph::self_loops_count() const {
        std::size_t count = 0;

        for (int v = 0; v < V_; ++v) {
            for (auto &w: adj_[v]) {
                if (w == v) {
                    ++count;
                }
            }
        }

        // in undirected graph, each edge is counted twice
        return count / 2;
    }

    std::size_t Graph::max_degree() const {
        std::size_t max_degree = 0;
        for (int v = 0; v < V_; ++v) {
            max_degree = std::max(max_degree, degree(v));
        }
        return max_degree;
    }

    std::string Graph::str() const {
        std::ostringstream oss;
        oss << V_ << " V_, " << E_ << " E_";
        for (int v = 0; v < V_; ++v) {
            oss << "\n" << v << ": ";
            for (auto &w: adj_[v]) {
                oss << w << " ";
            }
        }
        oss << std::endl;
        return oss.str();
    }

    void Graph::validate_vertex(int v) const {
        if ((v < 0) || (v >= V_))
            throw std::invalid_argument(std::string("v must be between 0 and ") + std::to_string(V_));
    }

    Graph load_graph_from_file(std::filesystem::path file_path) {
        std::ifstream in(file_path);

        int V;
        in >> V;

        int E;
        in >> E;

        if (E < 0) throw std::invalid_argument("Number of Edges in a Graph must be positive");

        Graph G(V);
        int v, w;
        for (int e = 0; e < E; ++e) {
            in >> v >> w;
            G.add_edge(v, w);
        }

        return G;
    }

}
