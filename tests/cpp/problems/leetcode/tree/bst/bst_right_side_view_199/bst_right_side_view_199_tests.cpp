#include <gtest/gtest.h>

#include <tree_node.hpp>
#include <bst_right_side_view.hpp>
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "../../../utils/include/file_utils.hpp"

using namespace algo::cpp::problems::bst::right_side_view_199;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class BSTRightSideViewTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
protected:
    BaseLoader loader;
    LoadBst bst_loader;
};


TEST_F(BSTRightSideViewTests, Scenario1) {
    BSTRightSideView solution;

    std::vector<int> expected{1, 3};


    std::string input("1,2,3,null,5,null,4");
    TreeNode* root = bst_loader.load_bst(input);
    auto result = solution.rightSideView(root);
    ASSERT_EQ(expected, result);
}

TEST_F(BSTRightSideViewTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("bst");
    auto usecase_dir = path / "bst_right_side_view_199";

    BSTRightSideView solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        TreeNode* root = tc.getInput();
        auto expected = tc.getExpected();
        auto actual = solution.rightSideView(root);
        ASSERT_EQ(expected, actual);
    }
}