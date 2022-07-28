#include <gtest/gtest.h>

#include <graph/cycle.hpp>

#include "graph_test_utils.hpp"

class CycleTests : public ::testing::Test {

protected:
    using Graph = algo::cpp::ds::Graph;
    using Cycle = algo::cpp::ds::Cycle;

protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CycleTests, VerifyCycle) {
    auto G = algo::cpp::ds::load_graph_from_file(get_graph_resource_path("tinyG.txt"));
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