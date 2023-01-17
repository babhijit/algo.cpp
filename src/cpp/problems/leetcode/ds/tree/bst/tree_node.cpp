#include "tree_node.hpp"


#include <queue>
#include <sstream>
#include <string>


namespace algo::cpp::leetcode::ds {

    std::string TreeNode::to_string(TreeNode *root) {
        std::queue<TreeNode *> q;
        add_to_queue(root, q);

        std::ostringstream oss;
        oss << "[";

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            oss << node->val;
            if (!q.empty()) {
                oss << ",";
            }
        }

        oss << "]";

        return oss.str();
    }

    void TreeNode::add_to_queue(TreeNode *node, std::queue<TreeNode *> &q) {
        if (!node) {
            return;
        }

        add_to_queue(node->left, q);
        q.push(node);
        add_to_queue(node->right, q);
    }
}