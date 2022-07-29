#ifndef ALGO_CPP_REVERSE_GRAPH_HPP
#define ALGO_CPP_REVERSE_GRAPH_HPP

namespace algo::cpp::ds {

    template<typename Graph>
    class ReverseGraph {
    public:
        Graph operator()(const Graph &G) {
            return reverse(G);
        }

    private:
        Graph reverse(const Graph &G) {
            Graph reversed_graph(G.V());

            for (int v = 0; v < reversed_graph.V(); ++v) {
                for (auto &w: G.adj(v)) {
                    reversed_graph.add_edge(v, w);
                }
            }
            return reversed_graph;
        }
    };
}

#endif //ALGO_CPP_REVERSE_GRAPH_HPP
