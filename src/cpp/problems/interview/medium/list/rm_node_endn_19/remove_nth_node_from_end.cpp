#include "remove_nth_node_from_end.hpp"

#include <cassert>
#include <stack>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::ll::rm_nth_end_node {

    ListNode *RemoveNthNodeFromEnd::removeNthFromEnd(ListNode *head, int n) {
        assert(head and "head must not be null");

        std::stack<ListNode*> nodes;
        std::size_t listSize {};
        for(auto it = head; it != nullptr; it = it->next) {
            nodes.push(it);
            ++listSize;
        }

        // edge case : moving the head
        if (listSize == n) {
            return head->next;
        }

        for(int i = 1; i <= n; ++i) {
            nodes.pop();
        }

        ListNode* prev = nodes.top();
        ListNode* next = prev->next->next;
        prev->next = next;
        return head;
    }
}