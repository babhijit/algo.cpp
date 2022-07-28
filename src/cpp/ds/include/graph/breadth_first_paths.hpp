#ifndef ALGO_CPP_BREADTH_FIRST_PATHS_HPP
#define ALGO_CPP_BREADTH_FIRST_PATHS_HPP

#include <list>
#include <vector>

#include "graph.hpp"

namespace algo::cpp::ds {

    class BreadthFirstPaths {
    private:
        std::vector<bool> marked_;
        std::vector<int> edge_to_;
        const int s_;

    public:
        explicit BreadthFirstPaths(const Graph &G, const int& s);

        bool has_path_to(const int& v) const { return marked_[v]; }

        std::list<int> path_to(const int& v) const;

    private:
        void bfs(const Graph &G, int s);
    };

}

#endif //ALGO_CPP_BREADTH_FIRST_PATHS_HPP
