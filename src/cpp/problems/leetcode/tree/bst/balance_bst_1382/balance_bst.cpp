#include "balance_bst.hpp"
#include "tree_node.hpp"

#include <vector>

namespace algo::cpp::leetcode {
    namespace problems::bst::balance_bst_1382 {

        void inOrder(ds::TreeNode *node, std::vector<int> &inOrderNodes) {
            if (not node) {
                return;
            }

            inOrder(node->left, inOrderNodes);
            inOrderNodes.push_back(node->val);
            inOrder(node->right, inOrderNodes);
        }

        ds::TreeNode* createBalancedBst(std::vector<int>& nodes, int begin, int end) {
           if (begin > end) { return nullptr; }

           auto mid = begin + (end - begin)/2;

           auto root = new ds::TreeNode(nodes[mid]);
           root->left = createBalancedBst(nodes, begin, mid - 1);
           root->right = createBalancedBst(nodes, mid + 1, end);

           return root;
        }


        ds::TreeNode *BalanceBST::balanceBST(ds::TreeNode *root) {

            std::vector<int> inOrderNodes;
            inOrder(root, inOrderNodes);

            return createBalancedBst(inOrderNodes, 0, inOrderNodes.size() - 1);
        }
    }
}
