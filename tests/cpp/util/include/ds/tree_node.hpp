#ifndef ALGO_CPP_TREE_NODE_HPP
#define ALGO_CPP_TREE_NODE_HPP

namespace algo::cpp::ds::tests::utils {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        explicit TreeNode(int val, TreeNode* left, TreeNode* right) :
            val(val), left(left), right(right) {}

        explicit TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}

        explicit TreeNode() : TreeNode(0) {}

        static void clear(TreeNode* node) {
            if(!node) {
                return;
            }

            if(node->left)  clear(node->left);
            if(node->right) clear(node->right);

            delete node;
        }
    };

}

#endif //ALGO_CPP_TREE_NODE_HPP
