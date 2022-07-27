#include <array>

#include <gtest/gtest.h>

#include <graph/bag.hpp>

class BagTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(BagTest, BagInitSuccess) {
    algo::cpp::ds::Bag<int> bag;
    ASSERT_TRUE(bag.empty());
}

TEST_F(BagTest, BagInitFail) {
    algo::cpp::ds::Bag<int> bag;
    ASSERT_NE(1, bag.size());
}

TEST_F(BagTest, AddToBag) {
    algo::cpp::ds::Bag<int> bag;

    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    ASSERT_EQ(items_to_add.size(), bag.size());
}

TEST_F(BagTest, TestIterators) {
    algo::cpp::ds::Bag<int> bag;
    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    auto items_it = std::begin(items_to_add);
    auto bag_it = std::begin(bag);
    while(bag_it != std::end(bag)) {
        ASSERT_EQ(*items_it++, *bag_it++);
    }
}

TEST_F(BagTest, TestReverseIterators) {
    algo::cpp::ds::Bag<int> bag;
    std::array<int, 6> items_to_add = {1, 2, 3, 4, 5, 6};
    for(int item: items_to_add) {
        bag.add(item);
    }

    auto items_it = std::rbegin(items_to_add);
    auto bag_it = std::rbegin(bag);
    while(bag_it != std::rend(bag)) {
        ASSERT_EQ(*items_it++, *bag_it++);
    }
}
