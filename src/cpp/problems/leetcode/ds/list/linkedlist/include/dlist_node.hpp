#pragma once

#include <string>

namespace algo::cpp::leetcode::ds {

    // doubly linked list
    struct DListNode {
        int val;
        DListNode *prev;
        DListNode *next;

        DListNode(int val_, DListNode* prev_, DListNode* next_) : val(val_), prev(prev_), next(next_) {}

        DListNode(int val_) : DListNode(val_, nullptr, nullptr) {}

        DListNode() : DListNode(0) {}

        static std::string to_string(DListNode *node);

        static bool equals(DListNode* a, DListNode* b);
    };

} // ds
