#ifndef ALGO_CPP_MERGE_K_SORTED_HPP
#define ALGO_CPP_MERGE_K_SORTED_HPP

#include <functional>
#include <queue>
#include <vector>

#include <list_node.hpp>

namespace algo::problems::leetcode::pq::merge_k_sorted {

    using namespace algo::cpp::leetcode::ds;

    class MergeKSorted {
        static constexpr auto greater = std::greater<int>{};
        struct ListNodeComparer {
            bool operator()(ListNode* p, ListNode* q) {
                return greater(p->val, q->val);
            }
        };

        using ListNodePQ = std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeComparer>;

    public:
        ListNode* mergeKLists(std::vector<ListNode*> &lists);

    private:
        void add_node_to_queue(ListNodePQ &pq, ListNode* node);
    };

}

#endif //ALGO_CPP_MERGE_K_SORTED_HPP
