#include <gtest/gtest.h>

#include "validate_bst.hpp"
#include "tree_node.hpp"
#include "test_case.hpp"

#include "loader/bst/load_bst.hpp"
#include "lc_file_utils.hpp"

using namespace algo::cpp::problems::bst::validate_bst;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class ValidateBstTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<std::string> const& rootNodes, bool expected) {
        LoadBst bstLoader;
        auto root = bstLoader.load_bst(rootNodes);

        runTest(root, expected);
    }

    static void runTest(TreeNode* root, bool expected) {
        ValidateBst solution;
        auto actual = solution.isValidBST(root);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(ValidateBstTests, Scenario1) {
    runTest({"5", "1", "4", "null", "null", "3", "6"},
            false);
}

TEST_F(ValidateBstTests, Scenario2) {
    runTest({"2","1","3"},
            true);
}

TEST_F(ValidateBstTests, Scenario3) {
    runTest({"2","2","2"},
            false);
}

TEST_F(ValidateBstTests, Scenario4) {
    runTest({"1","null","1"},
            false);
}

TEST_F(ValidateBstTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("bst");
    auto usecase_dir = path / "validate_bst_98";

    ValidateBst solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        runTest(tc.getRoot(), tc.getExpected());
    }
}