#include "remove_nth_node_from_end.hpp"

#include <cassert>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::ll::rm_nth_end_node {

    ListNode *RemoveNthNodeFromEnd::removeNthFromEnd(ListNode *head, int n) {
        assert(head and "head must not be null");

        std::size_t listSize{};
        for (auto it = head; it; it = it->next) {
            ++listSize;
        }

        // edge case: root node removal
        if (listSize == n) {
            return head->next;
        }

        auto parentIndex = listSize - n;
        ListNode* parent {head};
        for(auto i = 2; i <= parentIndex; ++i) {
            parent = parent->next;
        }

        ListNode* rmNode = parent->next;
        parent->next = parent->next->next;
        rmNode->next = {};
        return head;
    }
}