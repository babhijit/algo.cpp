#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/two_color.hpp>
#include <utils/graph_loader.hpp>

#include "res/graph_loader_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

class TwoColorTests : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;
    using TwoColor = algo::cpp::ds::TwoColor;

protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(TwoColorTests, BipartiteGraph) {
    using namespace algo::cpp::ds::tests::utils;
    auto G = load_graph("tinyBipartite.txt");
    TwoColor two_color(G);

    ASSERT_TRUE(two_color.is_bipartite());
}

TEST_F(TwoColorTests, NonBipartiteGraph) {
    using namespace algo::cpp::ds::tests::utils;
    auto G = load_graph("mediumG.txt");
    TwoColor two_color(G);

    ASSERT_FALSE(two_color.is_bipartite());
}