#ifndef ALGO_CPP_LOAD_BST_HPP
#define ALGO_CPP_LOAD_BST_HPP

#include <filesystem>
#include <string>
#include <vector>

//#include "ds/tree_node.hpp"
#include <tree_node.hpp>
#include "loader/base_loader.hpp"


/**
 * Loads BST Node from resource text file
 */

namespace algo::cpp::ds::tests::utils {

    using namespace algo::cpp::leetcode::ds;

    class LoadBst : public BaseLoader {
    public:
        TreeNode* operator()(const std::filesystem::path& file_name);

        TreeNode *load_bst(std::string input);

        TreeNode *load_bst(const std::vector<std::string>& values);

    private:

        TreeNode *create(const std::string& value);
    };

}

#endif //ALGO_CPP_LOAD_BST_HPP
