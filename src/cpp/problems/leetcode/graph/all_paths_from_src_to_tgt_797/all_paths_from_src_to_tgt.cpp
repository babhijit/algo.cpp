#include "all_paths_from_src_to_tgt.hpp"


#include <functional>

namespace algo::problems::leetcode::graph::all_paths_from_src_to_tgt {

    AllPathsFromSourceToTarget::Paths AllPathsFromSourceToTarget::allPathsSourceTarget(Graph &graph) {

        auto const target = graph.size() - 1;
        Path path{0};
        Paths paths;

        std::function<void(int, Path &)> dfs = [&](int v, Path &path) {
            if(v == target) {
                paths.emplace_back(Path(path));
                return;
            }

            for(int w: graph[v]) {
                path.push_back(w);
                dfs(w, path);
                path.pop_back();
            }
        };

        dfs(0, path);
        return paths;
    }

}
