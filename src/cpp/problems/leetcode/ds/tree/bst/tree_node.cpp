#include "tree_node.hpp"


#include <queue>
#include <sstream>
#include <string>


namespace algo::cpp::leetcode::ds {

    std::string TreeNode::to_string(TreeNode *root) {
        std::queue<TreeNode *> q;
        add_to_queue(root, q);

        return to_string_from_queue(q);
    }

    void TreeNode::add_to_queue(TreeNode *node, std::queue<TreeNode *> &q) {
        if (!node) {
            return;
        }

        add_to_queue(node->left, q);
        q.push(node);
        add_to_queue(node->right, q);
    }

    std::string TreeNode::preorder_to_string(TreeNode *root) {
        std::queue<TreeNode *> q;
        add_to_queue_preorder(root, q);

        return to_string_from_queue(q);
    }

    void TreeNode::add_to_queue_preorder(TreeNode *node,
                                         std::queue<TreeNode *> &q) {
        if (!node) {
            return;
        }

        q.push(node);
        add_to_queue(node->left, q);
        add_to_queue(node->right, q);
    }

    std::string TreeNode::to_string_from_queue(std::queue<TreeNode *> &q) {
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
}