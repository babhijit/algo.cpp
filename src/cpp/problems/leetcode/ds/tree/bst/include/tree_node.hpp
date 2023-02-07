#ifndef ALGO_CPP_LEETCODE_TREE_NODE_HPP
#define ALGO_CPP_LEETCODE_TREE_NODE_HPP

#include <queue>
#include <string>

namespace algo::cpp::leetcode::ds {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val, TreeNode *left, TreeNode *right) :
                val(val), left(left), right(right) {}

        TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}

        TreeNode() : TreeNode(0) {}

        static std::string to_string(TreeNode *root);

        static std::string preorder_to_string(TreeNode *root);

        static void add_to_queue(TreeNode *node, std::queue<TreeNode *> &q);

        static void add_to_queue_preorder(TreeNode *node, std::queue<TreeNode *> &q);

    private:
        static std::string to_string_from_queue(std::queue<TreeNode *> &q);

    };

}

#endif //ALGO_CPP_LEETCODE_TREE_NODE_HPP
