#ifndef ALGO_CPP_TREE_NODE_HPP
#define ALGO_CPP_TREE_NODE_HPP

#include <cstddef>
#include <queue>
#include <sstream>
#include <string>

namespace algo::cpp::ds {

    template<typename T>
    struct TreeNode {
    public:
        T value;
        TreeNode *left;
        TreeNode *right;
        std::size_t size;

    public:
        explicit TreeNode(T value, TreeNode *left, TreeNode *right) :
                value(value), left(left), right(right) {
            size = 1 + size(left) + size(right);
        }

        explicit TreeNode(T value) : TreeNode(value, nullptr, nullptr) {}


        static std::size_t size_of(TreeNode *node) {
            if (!node) return 0;

            return 1 + size_of(node->left) + size_of(node->right);
        }
    };
}

#endif //ALGO_CPP_TREE_NODE_HPP
