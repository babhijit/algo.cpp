#include "node.hpp"

#include <queue>
#include <sstream>
#include <string>


namespace algo::cpp::leetcode::ds {

    bool isNullNode(Node* node) { return node == nullptr; }

    std::string Node::to_string(Node *root) {
        std::queue<Node *> q;
        add_to_queue(root, q);

        return to_string_from_queue(q);
    }

    void Node::add_to_queue(Node *node, std::queue<Node *> &q) {
        if (not node) {
            return;
        }

        add_to_queue(node->left, q);
        q.push(node);
        add_to_queue(node->right, q);
    }

    std::string Node::preorder_to_string(Node *root) {
        std::queue<Node *> q;
        add_to_queue_preorder(root, q);

        return to_string_from_queue(q);
    }

    void Node::add_to_queue_preorder(Node *node,
                                         std::queue<Node *> &q) {
        if (!node) {
            return;
        }

        q.push(node);
        add_to_queue(node->left, q);
        add_to_queue(node->right, q);
    }

    std::string Node::to_string_from_queue(std::queue<Node *> &q) {
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

    bool equals(Node *a, Node *b) {
        if (not a or not b) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }

        // left subtree check
        if(a->left) {
            if (not equals(a->left, b->left)) {
                return false;
            }
        } else {
            return b->left == nullptr;
        }

        // right subtree check
        if (a->right) {
            if (not equals(a->right, b->right)) {
                return false;
            }
        } else {
            return b->right == nullptr;
        }

        return true;
    }
}