#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "bt_reverse_odd_level.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "../../../utils/include/file_utils.hpp"

using namespace algo::cpp::problems::bt::reverse_odd_levels;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class ReverseOddLevelsBTTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    BaseLoader loader;

public:
    void run_test(TreeNode *input, TreeNode *expected) {
        auto exec = [](TreeNode *input, TreeNode *expected) {
            ReverseOddLevelsBT solution;
            auto actual = solution.reverseOddLevels(input);

            ASSERT_EQ(TreeNode::to_string(expected), TreeNode::to_string(actual));
        };

        ASSERT_NO_THROW(exec(input, expected));
    }
};


TEST_F(ReverseOddLevelsBTTests, Scenario1) {
    std::string input("2,3,5,8,13,21,34");
    std::string output("2,5,3,8,13,21,34");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(ReverseOddLevelsBTTests, Scenario2) {
    std::string input("7,13,11");
    std::string output("7,11,13");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(ReverseOddLevelsBTTests, Scenario3) {
    std::string input("0,1,2,0,0,0,0,1,1,1,1,2,2,2,2");
    std::string output("0,2,1,0,0,0,0,2,2,2,2,1,1,1,1");
    TreeNode *root = TestCase::load_bst(input);
    TreeNode *expected = TestCase::load_bst(output);

    run_test(root, expected);
}

TEST_F(ReverseOddLevelsBTTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "reverse_odd_levels_2415";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        run_test(root, expected);
    }
}