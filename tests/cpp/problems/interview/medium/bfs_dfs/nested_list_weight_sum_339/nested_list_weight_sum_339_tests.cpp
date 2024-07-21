#include <gtest/gtest.h>

#include <nested_integer.hpp>
#include <nested_list_weighted_sum.hpp>

#include <vector>

using namespace algo::interview::medium::array::nested_list_weighted_sum;

class NestedListWeightedSumTests : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(NestedListWeightedSumTests, LeetCodeExample1) {
    NestedInteger ni1(1);
    NestedInteger ni2(2);

    NestedInteger n1List;
    n1List.add(ni1);
    n1List.add(ni1);

    NestedInteger n2List;
    n2List.add(ni2);
    n2List.add(ni2);

    std::vector<NestedInteger> nestedList{n1List, ni2, n1List};

    NestedListWeightedSum solution;
    ASSERT_EQ(10, solution.depthSum(nestedList));
}

TEST_F(NestedListWeightedSumTests, LeetCodeExample2) {
    NestedInteger ni6(6);
    NestedInteger niDepth2;
    niDepth2.add(ni6);
    NestedInteger ni4(4);
    NestedInteger niDepth3;
    niDepth3.add(ni4);
    niDepth3.add(niDepth2);
    std::vector<NestedInteger> nestedList{NestedInteger(1), niDepth3};

    NestedListWeightedSum solution;
    ASSERT_EQ(27, solution.depthSum(nestedList));
}

TEST_F(NestedListWeightedSumTests, LeetCodeExample3) {
    NestedInteger ni0(0);

    std::vector<NestedInteger> nestedList{ni0};

    NestedListWeightedSum solution;
    ASSERT_EQ(0, solution.depthSum(nestedList));
}

TEST_F(NestedListWeightedSumTests, MyTestCase1) {
    NestedInteger ni1(1);
    NestedInteger ni2(2);
    NestedInteger ni3(3);
    NestedInteger ni4(4);

    std::vector<NestedInteger> nestedList{ni1, ni2, ni3, ni4};

    NestedListWeightedSum solution;
    ASSERT_EQ(10, solution.depthSum(nestedList));
}
