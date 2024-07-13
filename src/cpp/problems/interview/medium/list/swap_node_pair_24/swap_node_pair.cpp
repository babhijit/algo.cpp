#include "swap_node_pair.hpp"

#include <memory>
#include <utility>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::ll::swap_node_pairs {

    using NodePair = std::pair<ListNode *, ListNode *>;

    ListNode *swapNodePairs(ListNode *first, ListNode *second) {
        if (not second) {
            return first;
        }
        auto t = second->next;
        second->next = first;
        first->next = t;
        return second;
    }

    ListNode *SwapNodePairs::swapPairs(ListNode *head) {
        auto dummyPtr = std::make_unique<ListNode>(-1);
        dummyPtr->next = head;

        auto parent = dummyPtr.get();
        while (parent->next) {
            auto first = parent->next;
            auto second = first->next;

            parent->next = swapNodePairs(first, second);
            parent = first; // now first is following the second
        }

        return dummyPtr->next;
    }
}