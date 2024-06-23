#pragma once

#include "tree_node.hpp"

#include <vector>

namespace algo::cpp { namespace problems::bt::bt_vert_order_traversal_314 {


    class BinaryTreeVerticalOrderTraversal {
    public:
        std::vector<std::vector<int>> verticalOrder(leetcode::ds::TreeNode *root);
    };

}}
