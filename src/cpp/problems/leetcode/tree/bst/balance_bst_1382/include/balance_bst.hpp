#pragma once

#include <memory>

namespace algo::cpp::leetcode {

    // forward declarations
    namespace ds {
        class TreeNode;
    } // algo::cpp::leetcode::ds

    namespace problems::bst::balance_bst_1382 {

        class BalanceBST {
        public:
            ds::TreeNode* balanceBST(ds::TreeNode *root);

        private:
            static void makeRotations(ds::TreeNode *vineHead, int nodesToRotate);

            static void rotateRight(ds::TreeNode *parent, ds::TreeNode *node);

            static void rotateLeft(ds::TreeNode *parent, ds::TreeNode *rightChild);

            static std::unique_ptr<ds::TreeNode> toVine(ds::TreeNode *root);

            static void toBalancedBst(ds::TreeNode *vineHead, int nodeCount);
        };

    } // algo::cpp::leetcode::problems::bst::balance_bst_1382
} // algo::cpp::leetcode