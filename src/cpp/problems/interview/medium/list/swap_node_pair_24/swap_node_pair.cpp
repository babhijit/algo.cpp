#include "swap_node_pair.hpp"

#include <stack>
#include <utility>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::ll::swap_node_pairs {

    using NodePair = std::pair<ListNode *, ListNode *>;

    ListNode *swapNodePairs(ListNode *first, ListNode *second, ListNode *tail) {
        if (second) {
            second->next = first;
        }
        first->next = tail;

        return second ? second : first;
    }

    ListNode *SwapNodePairs::swapPairs(ListNode *head) {
        std::stack<NodePair> nodePairs;
        auto it = head;
        while (it) {
            nodePairs.emplace(it, it->next);
            it = it->next;
            if (it) {
                it = it->next;
            }
        }

        ListNode *newHead = {};
        while (not nodePairs.empty()) {
            auto nodePair = nodePairs.top();
            nodePairs.pop();

            newHead = swapNodePairs(nodePair.first, nodePair.second, newHead);
        }

        return newHead;
    }
}