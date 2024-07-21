#pragma once

#include <tree_node.hpp>

namespace algo::interview::medium::tree::lowest_common_ancestor {

    using namespace algo::cpp::leetcode::ds;

    class LowestCommonAncestor {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    };

}