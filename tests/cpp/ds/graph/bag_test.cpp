#include <gtest/gtest.h>

#include <graph/bag.hpp>

TEST(BagTests, BagInit) {
    algo::cpp::ds::Bag<int> bag;
    ASSERT_EQ(0, bag.size());
}