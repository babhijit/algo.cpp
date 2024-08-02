#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "bst2dll.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "iview_file_utils.hpp"

#include <list>
#include <sstream>
#include <string>

using namespace algo::interview::medium::tree::bst2dll;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;


std::string toString(TreeNode* dlist) {
    std::ostringstream oss;
    oss << "[";

    while(dlist) {
        oss << dlist->val;
        if(dlist->right)
            oss << ",";
        dlist = dlist->right;
    }

    oss << "]";

    return oss.str();}


class Bst2DllTests : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}

    void runScenario(TreeNode* root, DListNode* expected) {
        Bst2Dll solution;
        auto actual = solution.treeToDoublyList(root);
        ASSERT_EQ(DListNode::to_string(expected), toString(actual));
    }

    void runTestCase(TestCase tc) {
        runScenario(tc.getRoot(), tc.getExpected());
    }

    void runTestCase(std::string root, std::vector<int> dlist) {
        TestCase tc(std::move(root), std::move(dlist));
        runTestCase(tc);
    }

protected:
    BaseLoader loader;
    LoadBst bst_loader;
};


TEST_F(Bst2DllTests, Scenario1) {
    runTestCase("4,2,5,1,3", {1, 2, 3, 4, 5});
}

TEST_F(Bst2DllTests, Scenario2) {
    runTestCase("2,1,3", {1, 2, 3});
}

TEST_F(Bst2DllTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "bst_to_sorted_doublylinkedlist_426";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        runTestCase(tc);
    }
}