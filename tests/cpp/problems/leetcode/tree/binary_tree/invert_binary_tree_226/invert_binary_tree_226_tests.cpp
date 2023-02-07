#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "invert_binary_tree.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "../../../utils/include/file_utils.hpp"

using namespace algo::cpp::problems::bt::invert_binary_tree;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class InvertBinaryTreeTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    BaseLoader loader;

public:
    void run_test(TreeNode *input, TreeNode *expected) {
        auto exec = [](TreeNode *input, TreeNode *expected) {
            InvertBinaryTree solution;
            auto actual = solution.invertTree(input);

            ASSERT_EQ(TreeNode::to_string(expected), TreeNode::to_string(actual));
        };

        ASSERT_NO_THROW(exec(input, expected));
    }
};


TEST_F(InvertBinaryTreeTests, Scenario1) {
    std::string input("2,1,3");
    std::string output("2,3,1");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(InvertBinaryTreeTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "invert_binary_tree_226";

    InvertBinaryTree solution;
    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        run_test(root, expected);
    }
}