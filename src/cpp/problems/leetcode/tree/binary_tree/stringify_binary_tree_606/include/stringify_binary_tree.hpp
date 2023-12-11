#pragma once

#include "tree_node.hpp"


namespace algo::cpp::problems::bt::stringify_binary_tree_606 {

    class StringifyBinaryTree {
    public:
        std::string tree2str(algo::cpp::leetcode::ds::TreeNode *root);

    private:
        static void stringifyPreorder(algo::cpp::leetcode::ds::TreeNode *node, std::ostringstream& oss);

        static bool isLeaf(algo::cpp::leetcode::ds::TreeNode *node);
        static void stringifyNode(algo::cpp::leetcode::ds::TreeNode *node, std::ostringstream& oss);
    };
}