#include "lowest_common_ancestor.hpp"

namespace algo::interview::medium::tree::lowest_common_ancestor_bst {

    TreeNode* lca(TreeNode* node, int p, int q) {
        int nodeVal = node->val;

        if (nodeVal < p and nodeVal < q) {
            // ancestor is the right subtree
            return lca(node->right, p, q);
        } else if (nodeVal > p and nodeVal > q) {
            // ancestor is in the left subtree
            return lca(node->left, p, q);
        }

        // we have found the common ancestor
        return node;
    }

    TreeNode *LowestCommonAncestor::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return lca(root, p->val, q->val);
    }

}