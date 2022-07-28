#include <gtest/gtest.h>


#include <graph/graph.hpp>
#include <graph/two_color.hpp>

#include "graph_test_utils.hpp"


class TwoColorTests : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;
    using TwoColor = algo::cpp::ds::TwoColor;

protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(TwoColorTests, BipartiteGraph) {
    auto G = algo::cpp::ds::load_graph_from_file(get_graph_resource_path("tinyBipartite.txt"));
    TwoColor two_color(G);

    ASSERT_TRUE(two_color.is_bipartite());
}

TEST_F(TwoColorTests, NonBipartiteGraph) {
    auto G = algo::cpp::ds::load_graph_from_file(get_graph_resource_path("mediumG.txt"));
    TwoColor two_color(G);

    ASSERT_FALSE(two_color.is_bipartite());
}