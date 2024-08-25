#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "complete_btree.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "iview_file_utils.hpp"

#include <list>
#include <string>

using namespace algo::interview::medium::tree::complete_btree;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;


class CheckCompleteTreeTests : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}

    void runScenario(TreeNode* root, bool expected) {
        CompleteBinaryTree solution;
        auto actual = solution.isCompleteTree(root);
        ASSERT_EQ(expected, actual);
    }

    void runTestCase(TestCase tc) {
        runScenario(tc.getRoot(), tc.getExpected());
    }

    void runTestCase(std::string root, bool expected) {
        TestCase tc(std::move(root), expected);
        runTestCase(tc);
    }

protected:
    BaseLoader loader;
    LoadBst bst_loader;
};


TEST_F(CheckCompleteTreeTests, Scenario1) {
    runTestCase("1,2,3,4,5,6", true);
}

TEST_F(CheckCompleteTreeTests, Scenario2) {
    runTestCase("1,2,3,4,5,null,7", false);
}

TEST_F(CheckCompleteTreeTests, Scenario3) {
    runTestCase("1,2,3,4,null,7", false);
}

TEST_F(CheckCompleteTreeTests, Scenario4) {
    runTestCase("1,2,3,null,null,4", false);
}

TEST_F(CheckCompleteTreeTests, Scenario5) {
    runTestCase("1,2,3,4,5,6,7,8,9,10,11,12,13,null,null,15", false);
}

TEST_F(CheckCompleteTreeTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "check_tree_completeness_958";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        runTestCase(tc);
    }
}