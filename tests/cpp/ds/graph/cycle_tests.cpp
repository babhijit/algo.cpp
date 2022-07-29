#include <gtest/gtest.h>

#include <graph/cycle.hpp>
#include <utils/graph_loader.hpp>

#include "ds_resource_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

class CycleTests : public ::testing::Test {

protected:
    using Graph = algo::cpp::ds::Graph;
    using Cycle = algo::cpp::ds::Cycle;

protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CycleTests, VerifyCycle) {
    algo::cpp::ds::utils::GraphLoader<Graph> loader;
    auto G = loader(get_graph_resource_path("tinyG.txt"));
    auto cycle = Cycle(G);

    ASSERT_TRUE(cycle.has_cycle());
}

TEST_F(CycleTests, VerifyAcyclic) {
    Graph G(4);
    G.add_edge(0, 1);
    G.add_edge(2, 3);

    Cycle cycle(G);
    ASSERT_FALSE(cycle.has_cycle());
}