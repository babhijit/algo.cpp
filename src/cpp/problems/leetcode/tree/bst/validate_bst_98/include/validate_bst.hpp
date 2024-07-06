#pragma once

#include "tree_node.hpp"

namespace algo::cpp::problems::bst::validate_bst {

    using namespace algo::cpp::leetcode::ds;

    class ValidateBst {
    public:
        bool isValidBST(TreeNode* root);
    private:
        bool isValidBST(TreeNode* node, int min, int max);
    };

}