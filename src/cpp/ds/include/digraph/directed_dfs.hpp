#ifndef ALGO_CPP_DIRECTED_DFS_HPP
#define ALGO_CPP_DIRECTED_DFS_HPP


#include <iterator>
#include <vector>

#include "digraph.hpp"


namespace algo::cpp::ds {

    class DirectedDFS {
    public:
        explicit DirectedDFS(const Digraph &G, int s);

        template<typename ForwardIterator>
        explicit DirectedDFS(const Digraph &G, ForwardIterator start, ForwardIterator end) : marked_(G.V(), false) {
            while (start != end) {
                if (!marked_[*start]) {
                    dfs(G, *start);
                }
                ++start;
            }
        }

        bool visited(int v) const;

    private:
        void dfs(const Digraph &G, int v);

    private:
        std::vector<bool> marked_;
    };
}

#endif //ALGO_CPP_DIRECTED_DFS_HPP
