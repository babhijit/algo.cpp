#include "balance_bst.hpp"
#include "tree_node.hpp"

#include <cassert>
#include <cmath>
#include <memory>


namespace algo::cpp::leetcode::problems::bst::balance_bst_1382 {

    using TreeNodePtr = std::unique_ptr<ds::TreeNode>;

    ds::TreeNode *BalanceBST::balanceBST(ds::TreeNode *root) {
        if (not root) {
            return nullptr;
        }

        auto vine = toVine(root);

        auto getNodesCount = [](ds::TreeNode* vineHead) {
            int count{0};
            for(auto itr = vineHead->right; itr; itr = itr->right) {
                ++count;
            }
            return count;
        };

        auto vineHead = vine.get();
        auto totalNodes = getNodesCount(vineHead);
        toBalancedBst(vineHead, totalNodes);

        // remove the dummy vineHead node
        return vineHead->right;
    }

    void BalanceBST::rotateLeft(ds::TreeNode *parent, ds::TreeNode *rightChild) {
        assert(parent);  assert(rightChild);
        auto rrChild = rightChild->right; // right child's right node
        rightChild->right = rrChild->left;
        rrChild->left = rightChild;

        parent->right = rrChild;
    }

    void BalanceBST::rotateRight(ds::TreeNode *parent, ds::TreeNode *node) {
        assert(parent);     assert(node);

        // rotate parent's right child
        auto tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    void BalanceBST::makeRotations(ds::TreeNode *vineHead, int nodesToRotate) {
        auto itr = vineHead;
        while (nodesToRotate > 0) {
            rotateLeft(itr, itr->right);
            itr = itr->right;
            --nodesToRotate;
        }
    }

     TreeNodePtr BalanceBST::toVine(ds::TreeNode *root) {
        auto vineHead = std::make_unique<ds::TreeNode>(0, nullptr, root);

        auto itr = vineHead.get();
        while (itr->right) {
            // right rotate if right child has left subtree
            if (itr->right->left) {
                rotateRight(itr, itr->right);
            } else {
                itr = itr->right;
            }
        }

        return vineHead;
    }

    void BalanceBST::toBalancedBst(ds::TreeNode *vineHead, int nodeCount) {
        int leafNodes = std::pow(2, std::floor(std::log2(nodeCount + 1))) - 1;

        int nodesToRotate = nodeCount - leafNodes;
        makeRotations(vineHead, nodesToRotate);
        int remainingNodesToRotate = leafNodes;
        while (remainingNodesToRotate > 1) {
            remainingNodesToRotate /= 2;
            makeRotations(vineHead, remainingNodesToRotate);
        }
    }
}

