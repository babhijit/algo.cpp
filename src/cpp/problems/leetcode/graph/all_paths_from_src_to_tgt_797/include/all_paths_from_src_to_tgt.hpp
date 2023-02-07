#ifndef ALGO_CPP_ALL_PATHS_FROM_SRC_TO_TGT_HPP
#define ALGO_CPP_ALL_PATHS_FROM_SRC_TO_TGT_HPP

#include <vector>

namespace algo::problems::leetcode::graph::all_paths_from_src_to_tgt {

    class AllPathsFromSourceToTarget {
    public:
        using Graph = std::vector<std::vector<int>>;
        using Path = std::vector<int>;
        using Paths = std::vector<Path>;

        Paths allPathsSourceTarget(Graph &graph);
    };
}

#endif //ALGO_CPP_ALL_PATHS_FROM_SRC_TO_TGT_HPP
