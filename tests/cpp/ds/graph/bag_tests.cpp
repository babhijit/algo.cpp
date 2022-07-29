#include <array>

#include <gtest/gtest.h>

#include "sequence/bag.hpp"


class BagTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(BagTests, BagInitSuccess) {
    algo::cpp::ds::Bag<int> bag;
    ASSERT_TRUE(bag.empty());
}

TEST_F(BagTests, BagInitFail) {
    algo::cpp::ds::Bag<int> bag;
    ASSERT_NE(1, bag.size());
}

TEST_F(BagTests, AddToBag) {
    algo::cpp::ds::Bag<int> bag;

    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    ASSERT_EQ(items_to_add.size(), bag.size());
}

TEST_F(BagTests, TestIterators) {
    algo::cpp::ds::Bag<int> bag;
    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    ASSERT_TRUE(std::equal(bag.rbegin(), bag.rend(), items_to_add.begin(), items_to_add.end()));
}

TEST_F(BagTests, TestReverseIterators) {
    algo::cpp::ds::Bag<int> bag;
    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    ASSERT_TRUE(std::equal(bag.rbegin(), bag.rend(), items_to_add.begin(), items_to_add.end()));
}
