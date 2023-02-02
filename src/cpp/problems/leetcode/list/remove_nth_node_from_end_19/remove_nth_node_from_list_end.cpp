#include "remove_nth_node_from_list_end.hpp"


#include <cassert>
#include <stack>


namespace algo::problems::leetcode::list::remove_nth_node_from_list_end {

    ListNode *RemoveNthNodeFromListEnd::removeNthNodeFromEnd(ListNode *head, int n) {
        assert(head != nullptr);
        assert(n > 0);

        std::stack<ListNode *> stack;

        for (auto node = head; node != nullptr; node = node->next) {
            stack.push(node);
        }

        ListNode *current = nullptr;
        while (n--) {
            current = stack.top();
            stack.pop();
        }

        // edge case: deletion of head node
        if (stack.empty()) {
            head = current->next;
        } else {
            auto parent = stack.top();
            parent->next = current->next;
        }

        delete current;

        return head;
    }
} // remove_nth_node_from_list_end