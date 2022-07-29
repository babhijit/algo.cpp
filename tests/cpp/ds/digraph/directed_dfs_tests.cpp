#include <gtest/gtest.h>

#include <digraph/digraph.hpp>
#include <digraph/directed_dfs.hpp>

#include <utils/graph_loader.hpp>

#include <ds_loader_utils.hpp>


class DirectedDFSTests : public ::testing::Test {
protected:
    using Digraph = algo::cpp::ds::Digraph;
    using DirectedDFS = algo::cpp::ds::DirectedDFS;

    std::unique_ptr<Digraph> G_;

protected:
    void SetUp() override {
        using namespace algo::cpp::ds::tests::utils;
        auto G = load_digraph("tinyDG.txt");
        G_ = std::make_unique<Digraph>(std::move(G));
    }

    void TearDown() override {
        G_.reset();
    }
};


TEST_F(DirectedDFSTests, VisitedPositive) {
    DirectedDFS directed_dfs(*G_, 7);
    ASSERT_TRUE(directed_dfs.visited(4));
}

TEST_F(DirectedDFSTests, VisitedNegative) {
    DirectedDFS directed_dfs(*G_, 9);
    ASSERT_FALSE(directed_dfs.visited(6));
}