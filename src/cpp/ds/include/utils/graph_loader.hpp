#ifndef ALGO_CPP_GRAPH_LOADER_HPP
#define ALGO_CPP_GRAPH_LOADER_HPP


#include <filesystem>
#include <fstream>
#include <string>

namespace algo::cpp::ds::utils {

    template <class Graph>
    class GraphLoader {
    public:
        Graph operator()(const std::filesystem::path& filepath) {
            std::ifstream in(filepath);
            if (!in.is_open()) {
                throw std::runtime_error(std::string("Unable to open file: ") + filepath.string());
            }

            return load(in);
        }

    private:
        Graph load(std::ifstream& in) {
            int total_vertices;
            in >> total_vertices;

            Graph G(total_vertices);
            int total_edges;
            in >> total_edges;

            if (total_edges < 0) {
                throw std::invalid_argument("Number of edges must be positive");
            }

            int v, w;
            for (int e = 0; e < total_edges; ++e) {
                in >> v >> w;
                G.add_edge(v, w);
            }

            return G;
        }
    };

}

#endif //ALGO_CPP_GRAPH_LOADER_HPP
