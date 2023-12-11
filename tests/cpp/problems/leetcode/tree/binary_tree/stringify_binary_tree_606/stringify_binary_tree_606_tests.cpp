#include "test_case.hpp"

#include "stringify_binary_tree.hpp"

#include "tree_node.hpp"

#include "lc_file_utils.hpp"

#include "res/ds_resource_utils.hpp"
#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"

#include <gtest/gtest.h>


using namespace algo::cpp::problems::bt::stringify_binary_tree_606;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;


class BSTStringifyBinaryTreeTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    void run_test(TreeNode *root, std::string const &expected) {
        StringifyBinaryTree solution;
        auto actual = solution.tree2str(root);

        ASSERT_EQ(expected, actual);
    }

    void run_test_case(std::string const &input, std::string const &expected) {
        TreeNode *root = TestCase::loadBst(input);
        run_test(root, expected);
    }

    void run_test_case(std::filesystem::path const &testcase) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        run_test(root, expected);
    }
};

TEST_F(BSTStringifyBinaryTreeTests, Scenario1) {
    run_test_case("1,2,3,4", "1(2(4))(3)");
}

TEST_F(BSTStringifyBinaryTreeTests, Scenario2) {
    run_test_case("1,2,3,null,4", "1(2()(4))(3)");
}

TEST_F(BSTStringifyBinaryTreeTests, RunTestsFromResources) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "stringify_binary_tree_606";


    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [&](auto const &testcase) {
        run_test_case(testcase);
    });
}