#include <gtest/gtest.h>

#include "level_order_traversal.hpp"
#include "tree_node.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "lc_file_utils.hpp"

using namespace algo::cpp::problems::bst::binary_level_order_traversal_102;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class LargestLevelOrderTraversalTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
protected:
    using Matrix = std::vector<std::vector<int>>;
    BaseLoader loader;
    LoadBst bst_loader;
};


TEST_F(LargestLevelOrderTraversalTests, Scenario1) {
    LevelOrderTraversal solution;

    Matrix expected({{3},
                     {9,  20},
                     {15, 7}});


    std::vector<std::string> input{"3","9","20","null","null","15","7"};
    TreeNode* root = bst_loader.load_bst(input);
    auto result = solution.levelOrder(root);
    ASSERT_EQ(expected, result);
}

TEST_F(LargestLevelOrderTraversalTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("bst");
    auto usecase_dir = path / "binary_level_order_traversal_102";

    LevelOrderTraversal solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        TreeNode* root = bst_loader.load_bst(input);
        auto actual = solution.levelOrder(root);
        ASSERT_EQ(expected, actual);
    }
}