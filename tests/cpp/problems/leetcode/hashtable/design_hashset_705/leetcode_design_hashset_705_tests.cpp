#include <gtest/gtest.h>

#include "my_hashset.hpp"

using namespace algo::cpp::problems::hashtable::design_hashset_705;

class DesignHashsetTests : public ::testing::Test {
protected:
    MyHashSet hashset_;

protected:
    void SetUp() override {}

    void TearDown() override {
        hashset_.clear();
    }
};


TEST_F(DesignHashsetTests, ADD_1) {
    ASSERT_FALSE(hashset_.contains(1));
    hashset_.add(1);
    ASSERT_TRUE(hashset_.contains(1));
}

TEST_F(DesignHashsetTests, ADD_2) {
    ASSERT_FALSE(hashset_.contains(2));
    hashset_.add(2);
    ASSERT_TRUE(hashset_.contains(2));
}

TEST_F(DesignHashsetTests, CONTAINS_1) {
    hashset_.add(1);
    ASSERT_TRUE(hashset_.contains(1));
}

TEST_F(DesignHashsetTests, CONTAINS_3) {
    ASSERT_FALSE(hashset_.contains(3));
}

TEST_F(DesignHashsetTests, REMOVE_2) {
    hashset_.add(2);
    ASSERT_TRUE(hashset_.contains(2));
    hashset_.remove(2);
    ASSERT_FALSE(hashset_.contains(2));
}