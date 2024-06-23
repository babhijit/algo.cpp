#include "test_case.hpp"

#include "bt_vert_order_traversal.hpp"

#include "tree_node.hpp"

#include "lc_file_utils.hpp"

#include "loader/base_loader.hpp"

#include <gtest/gtest.h>

using namespace algo::cpp::problems::bt::bt_vert_order_traversal_314;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;


class BSTStringifyBinaryTreeTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void run_test(TreeNode *root, std::vector<std::vector<int>> const &expected) {
        BinaryTreeVerticalOrderTraversal solution;
        auto actual = solution.verticalOrder(root);

        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(std::string const &input, std::vector<std::vector<int>> const &expected) {
        TreeNode *root = TestCase::loadBst(input);
        run_test(root, expected);
    }

    static void run_test_case(std::filesystem::path const &testcase) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        run_test(root, expected);
    }
};

TEST_F(BSTStringifyBinaryTreeTests, Scenario1) {
    run_test_case("3,9,20,null,null,15,7", {{9},{3,15},{20},{7}});
}

TEST_F(BSTStringifyBinaryTreeTests, Scenario2) {
    run_test_case("3,9,8,4,0,1,7", {{4},{9},{3,0,1},{8},{7}});
}

TEST_F(BSTStringifyBinaryTreeTests, RunTestsFromResources) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "bt_vert_order_traversal_314";


    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [&](auto const &testcase) {
        run_test_case(testcase);
    });
}