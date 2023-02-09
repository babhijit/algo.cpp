#include "merge_k_sorted.hpp"

#include <memory>

namespace algo::problems::leetcode::list::merge_k_sorted {

    ListNode *MergeKSorted::mergeKLists(std::vector<ListNode *> &lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeComparer> pq;

        auto const K = lists.size();
        auto merge_head = std::make_unique<ListNode>();
        auto* merged = merge_head.get();
        ListNode* res_node = merged;

        std::vector<ListNode* > indices(K);
        for (auto& head: lists) {
            add_node_to_queue(pq, head);
        }

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            res_node->next = node;
            add_node_to_queue(pq, node->next);
            res_node = res_node->next;
        }

        return merged->next;
    }

    void MergeKSorted::add_node_to_queue(MergeKSorted::ListNodePQ &pq, ListNode *node) {
        if(node) {
            pq.push(node);
        }
    }

}
