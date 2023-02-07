#ifndef ALGO_CPP_BT_FLATTEN_TO_LIST_HPP
#define ALGO_CPP_BT_FLATTEN_TO_LIST_HPP

#include <utility>


#include <tree_node.hpp>

namespace algo::cpp::problems::bt::flatten_binary_tree_to_list {

    using namespace algo::cpp::leetcode::ds;

    class FlattenBinaryTreeToList {

    public:
        void flatten(TreeNode *root);

    private:
        static bool is_leaf(TreeNode *node);
        static bool is_null(TreeNode *node);

        TreeNode* preorder(TreeNode* node);
    };

} // flatten_binary_tree_to_list

#endif // ALGO_CPP_BT_FLATTEN_TO_LIST_HPP
