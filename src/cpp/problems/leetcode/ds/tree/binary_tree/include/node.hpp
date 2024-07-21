#ifndef ALGO_CPP_LEETCODE_TREE_NODE_HPP
#define ALGO_CPP_LEETCODE_TREE_NODE_HPP

#include <queue>
#include <string>

namespace algo::cpp::leetcode::ds {

    struct Node {
        int val;
        Node *left;
        Node *right;
        Node* parent;

        Node(int val, Node *left, Node *right, Node* parent) :
                val(val), left(left), right(right), parent(parent) {}

        Node(int val, Node *left, Node *right) : Node(val, left, right, nullptr) {}

        explicit Node(int val) : Node(val, nullptr, nullptr) {}

        Node() : Node(0) {}

        static std::string to_string(Node *root);

        static std::string preorder_to_string(Node *root);

        static void add_to_queue(Node *node, std::queue<Node *> &q);

        static void add_to_queue_preorder(Node *node, std::queue<Node *> &q);

        friend bool equals(Node* a, Node* b);

    private:
        static std::string to_string_from_queue(std::queue<Node *> &q);

    };

    bool equals(Node *a, Node *b);

}

#endif //ALGO_CPP_LEETCODE_TREE_NODE_HPP
