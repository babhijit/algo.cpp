#include <string>

#include <gtest/gtest.h>

#include <digraph/digraph.hpp>

#include "res/graph_loader_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

class DigraphFromFileTests : public ::testing::Test {

protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(DigraphFromFileTests, TinyDG) {

    auto G = load_digraph("tinyDG.txt");

    ASSERT_EQ(13, G.V());
    ASSERT_EQ(22, G.E());
}

TEST_F(DigraphFromFileTests, MediumDG) {

    auto G = load_digraph("mediumDG.txt");

    ASSERT_EQ(50, G.V());
    ASSERT_EQ(147, G.E());
}
