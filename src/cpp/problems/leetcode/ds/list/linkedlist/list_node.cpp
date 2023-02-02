#include "list_node.hpp"

#include <sstream>


namespace algo::cpp::leetcode::ds {

    std::string ListNode::to_string(ListNode *node) {

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

} // ds