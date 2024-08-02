#include "dlist_node.hpp"

#include <sstream>


namespace algo::cpp::leetcode::ds {

    std::string DListNode::to_string(DListNode *node) {

        std::ostringstream oss;
        oss << "[";

        while(node) {
            oss << node->val;
            if(node->next)
                oss << ",";
            node = node->next;
        }

        oss << "]";

        return oss.str();
    }

    bool DListNode::equals(DListNode *a, DListNode *b) {
        auto x = a;
        auto y = b;
        while ((x != nullptr) and (y != nullptr)) {
            if(x->val != y->val) {
                return false;
            }
            x = x->next;
            y = y->next;
        }

        return ((x == nullptr) and (y == nullptr));
    }

} // ds