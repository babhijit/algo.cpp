#include "swap_node_pair.hpp"

#include <stack>
#include <utility>

namespace algo::interview::medium::ll::swap_node_pairs {

    ListNode* swapNodePairs(ListNode* first, ListNode* second) {
        if (not second) {
            return first;
        }

        ListNode* t = second->next;
        second->next = first;
        first->next = t;
        return second;
    }

    ListNode *SwapNodePairs::swapPairs(ListNode *head) {
        using NodePair = std::pair<ListNode*, ListNode*>;

        std::stack<NodePair> nodePairs;
        auto it = head;
        while (it) {
            nodePairs.emplace(it , it->next);
            it = it->next;
            if (it) {
                it = it->next;
            }
        }

        ListNode* newHead = {};
        ListNode* t = {};
        while(not nodePairs.empty()) {
            auto nodePair = nodePairs.top();
            nodePairs.pop();

            auto f = nodePair.first;
            auto s = nodePair.second;
            if (not s) {
                newHead = f;
                t = f;
                continue;
            }
            s->next = f;
            f->next = t;
            t = s;
            newHead = s;
        }

        return newHead;
    }
}