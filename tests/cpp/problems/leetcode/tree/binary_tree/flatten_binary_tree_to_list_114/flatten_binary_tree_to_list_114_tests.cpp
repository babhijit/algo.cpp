#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "flatten_binary_tree_to_list.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "../../../utils/include/file_utils.hpp"

using namespace algo::cpp::problems::bt::flatten_binary_tree_to_list;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class FlattenBinaryTreeToListTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    void run_test(TreeNode *root, TreeNode *expected) {

        auto exec = [](TreeNode *root, TreeNode *expected) {
            FlattenBinaryTreeToList solution;
            solution.flatten(root);

            ASSERT_EQ(TreeNode::preorder_to_string(expected), TreeNode::preorder_to_string(root));
        };

        ASSERT_NO_THROW(exec(root, expected));

    }
};


TEST_F(FlattenBinaryTreeToListTests, SimpleBalanceBinaryTree) {
    std::string input("1,2,3");
    std::string output("1,null,2,null,3,null");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(FlattenBinaryTreeToListTests, OneNodeBinaryTree) {
    std::string input("1,null,null");
    std::string output("1,null,null");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(FlattenBinaryTreeToListTests, LeftOnlyBinaryTree) {
    std::string input("1,2,null");
    std::string output("1,null, 2 ,null");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(FlattenBinaryTreeToListTests, RightOnlyBinaryTree) {
    std::string input("1,null, 2");
    std::string output("1,null, 2 ,null");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(FlattenBinaryTreeToListTests, LeetCodeExample1) {
    std::string input("1,2,5,3,4,null,6");
    std::string output("1,null,2,null,3,null,4,null,5,null,6");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(FlattenBinaryTreeToListTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "flatten_binary_tree_to_list_114";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        run_test(root, expected);
    }
}