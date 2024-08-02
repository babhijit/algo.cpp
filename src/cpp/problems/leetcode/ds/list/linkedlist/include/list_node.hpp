#pragma once

#include <string>

namespace algo::cpp::leetcode::ds {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int val_, ListNode* next_) : val(val_), next(next_) {}

        ListNode(int val_) : ListNode(val_, nullptr) {}

        ListNode() : ListNode(0) {}

        static std::string to_string(ListNode *node);

    };

} // ds

