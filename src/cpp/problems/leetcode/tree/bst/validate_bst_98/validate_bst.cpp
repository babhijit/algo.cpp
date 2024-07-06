#include "validate_bst.hpp"

#include <cassert>
#include <limits>

namespace algo::cpp::problems::bst::validate_bst {

    bool withinRange(int min, int value, int max) {
        return (value > min) and (value < max);
    }

    bool isLeaf(TreeNode *node) {
        return (not node->left) and (not node->right);
    }

    bool ValidateBst::isValidBST(TreeNode *root) {
        assert(root and "root must be non null");
        if (isLeaf(root)) {
            return true;
        }

        return isValidBST(root->left, std::numeric_limits<int>::min(), root->val) and
               isValidBST(root->right, root->val, std::numeric_limits<int>::max());
    }

    bool ValidateBst::isValidBST(TreeNode *node, int min, int max) {
        if (not node) {
            return true;
        }

        if (not withinRange(min, node->val, max)) {
            return false;
        }

        if (isLeaf(node)) {
            return true;
        }

        return isValidBST(node->left, min, node->val) and
               isValidBST(node->right, node->val, max);
    }

}