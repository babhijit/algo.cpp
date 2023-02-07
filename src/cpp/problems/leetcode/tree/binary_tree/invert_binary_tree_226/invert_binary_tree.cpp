#include "invert_binary_tree.hpp"


namespace algo::cpp::problems::bt::invert_binary_tree {

    TreeNode *InvertBinaryTree::invertTree(TreeNode *root) {
        if(root) {
            auto left = root->left;
            auto right = root->right;
            root->left = invertTree(right);
            root->right = invertTree(left);
        }
        return root;
    }

}
