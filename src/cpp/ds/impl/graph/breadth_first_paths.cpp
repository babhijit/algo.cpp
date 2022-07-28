#include <queue>

#include "breadth_first_paths.hpp"

namespace algo::cpp::ds {

    BreadthFirstPaths::BreadthFirstPaths(const Graph &G, const int& s) :
            marked_(G.V(), false),
            edge_to_(G.V(), -1),
            s_(s) {
        bfs(G, s);
    }


    void BreadthFirstPaths::bfs(const Graph &G, int s) {
        std::queue<int> queue;
        marked_[s] = true;
        edge_to_[s] = s;
        queue.push(s);

        while (!queue.empty()) {
            int v = queue.back();
            queue.pop();
            for (auto &w: G.adj(v)) {
                if (!marked_[w]) {
                    edge_to_[w] = v;
                    marked_[w] = true;
                    queue.push(w);
                }
            }
        }
    }

    std::list<int> BreadthFirstPaths::path_to(const int& v) const {
        std::list<int> path;

        if (has_path_to(v)) {
            for (int x = v; x != s_; x = edge_to_[x]) {
                path.push_front(x);
            }
            path.push_front(s_);
        }

        return path;
    }
}
