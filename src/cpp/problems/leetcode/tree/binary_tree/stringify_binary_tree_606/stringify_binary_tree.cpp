#include "stringify_binary_tree.hpp"

#include <sstream>

using namespace algo::cpp::leetcode::ds;

namespace algo::cpp::problems::bt::stringify_binary_tree_606 {

    std::string StringifyBinaryTree::tree2str(TreeNode *root) {
        std::ostringstream oss;

        stringifyPreorder(root, oss);

        return oss.str();
    }

    void StringifyBinaryTree::stringifyPreorder(algo::cpp::leetcode::ds::TreeNode *node, std::ostringstream &oss) {
        if (not node) {
            return;
        }

        oss << node->val;

        if (isLeaf(node)) {
            return;
        }

        // no left child
        if (not node->left) {
            oss << "()";
        } else {
            stringifyNode(node->left, oss);
        }

        // process right child
        if (node->right) {
            stringifyNode(node->right, oss);
        }
    }

    bool StringifyBinaryTree::isLeaf(algo::cpp::leetcode::ds::TreeNode *node) {
        return not node->left and not node->right;
    }

    void StringifyBinaryTree::stringifyNode(algo::cpp::leetcode::ds::TreeNode *node, std::ostringstream &oss) {
        oss << "(";
        stringifyPreorder(node, oss);
        oss << ")";
    }
}