#include "tree_node.hpp"


#include <queue>
#include <sstream>
#include <string>


namespace algo::cpp::leetcode::ds {

    bool isNullNode(TreeNode* node) { return node == nullptr; }

    std::string TreeNode::to_string(TreeNode *root) {
        std::queue<TreeNode *> q;
        add_to_queue(root, q);

        return to_string_from_queue(q);
    }

    void TreeNode::add_to_queue(TreeNode *node, std::queue<TreeNode *> &q) {
        if (not node) {
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

    bool TreeNode::operator==(TreeNode *other) const {
        if (not other) {
            return false;
        }

        if (val != other->val) {
            return false;
        }

        // left subtree check
        if(left) {
            if (left != other->left) {
                return false;
            }
        } else {
            return other->left == nullptr;
        }

        // right subtree check
        if (right) {
            if (right != other->right) {
                return false;
            }
        } else {
            return other->right == nullptr;
        }

        return true;
    }

    bool TreeNode::operator!=(TreeNode *other) const {
        bool isEqual = (this == other);
        return not isEqual;
    }
}