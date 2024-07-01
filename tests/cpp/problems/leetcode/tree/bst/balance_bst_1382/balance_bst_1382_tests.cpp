#include <gtest/gtest.h>

#include "balance_bst.hpp"
#include "tree_node.hpp"
#include "test_case.hpp"

#include "loader/bst/load_bst.hpp"
#include "lc_file_utils.hpp"

using namespace algo::cpp::leetcode::problems::bst::balance_bst_1382;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class BalanceBstTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<std::string> const& rootNodes, std::vector<std::string> const& expectedNodes) {
        LoadBst bstLoader;
        auto root = bstLoader.load_bst(rootNodes);
        auto expected = bstLoader.load_bst(expectedNodes);

        runTest(root, expected);
    }

    static void runTest(TreeNode* root, TreeNode* expected) {
        BalanceBST solution;
        auto actual = solution.balanceBST(root);
        ASSERT_TRUE(equals(actual, expected));
    }
};


TEST_F(BalanceBstTests, Scenario1) {
    runTest({"1","null","2","null", "3","null","4","null", "null"},
            {"3","2","4","1","null","null","null"});
}

TEST_F(BalanceBstTests, Scenario2) {
    runTest({"2","1","3"},
            {"2","1","3"});
}

TEST_F(BalanceBstTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("bst");
    auto usecase_dir = path / "balance_bst_1382";

    BalanceBST solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        runTest(tc.getRoot(), tc.getExpected());
    }
}