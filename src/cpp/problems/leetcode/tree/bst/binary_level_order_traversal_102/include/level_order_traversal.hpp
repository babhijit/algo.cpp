#ifndef ALGO_CPP_LEVEL_ORDER_TRAVERSAL_HPP
#define ALGO_CPP_LEVEL_ORDER_TRAVERSAL_HPP

#include <queue>
#include <vector>

#include "tree_node.hpp"

namespace algo::cpp::problems::bst::binary_level_order_traversal_102 {

    using namespace algo::cpp::leetcode::ds;

    class LevelOrderTraversal {
        using Matrix = std::vector<std::vector<int>>;

    private:
        std::queue<TreeNode*> process_level(Matrix &result, std::queue<TreeNode*> &level);
        void push_child_nodes(std::queue<TreeNode*> &level, TreeNode *node);
        void push_node(std::queue<TreeNode*> &level, TreeNode *node);

    public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root);
    };

}


#endif //ALGO_CPP_LEVEL_ORDER_TRAVERSAL_HPP
