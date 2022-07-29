#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/two_color.hpp>
#include <utils/graph_loader.hpp>

#include "ds_resource_utils.hpp"

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
    algo::cpp::ds::utils::GraphLoader<Graph> loader;
    auto G = loader(get_graph_resource_path("tinyBipartite.txt"));
    TwoColor two_color(G);

    ASSERT_TRUE(two_color.is_bipartite());
}

TEST_F(TwoColorTests, NonBipartiteGraph) {
    algo::cpp::ds::utils::GraphLoader<Graph> loader;
    auto G = loader(get_graph_resource_path("mediumG.txt"));
    TwoColor two_color(G);

    ASSERT_FALSE(two_color.is_bipartite());
}