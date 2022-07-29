#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/depth_first_search.hpp>
#include <utils/graph_loader.hpp>

#include "ds_resource_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

class DepthFirstSearchTests : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;
    std::unique_ptr<Graph> G_;

protected:
    void SetUp() override {
        algo::cpp::ds::utils::GraphLoader<Graph> loader;
        auto G = loader(get_graph_resource_path("tinyG.txt"));
        G_ = std::make_unique<Graph>(std::move(G));
    }

    void TearDown() override {
        G_.reset();
    }
};

TEST_F(DepthFirstSearchTests, NotConnectedTestForVertices0n7) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 0);
    ASSERT_FALSE(dfs.marked(7));
}

TEST_F(DepthFirstSearchTests, NotConnectedTestForVertices0n9) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 0);
    ASSERT_FALSE(dfs.marked(9));
}

TEST_F(DepthFirstSearchTests, ConnectedTestForVertices9n11) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 9);
    ASSERT_TRUE(dfs.marked(11));
}

TEST_F(DepthFirstSearchTests, ConnectedTestForVertices9n10) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 9);
    ASSERT_TRUE(dfs.marked(10));
}

TEST_F(DepthFirstSearchTests, ConnectedTestForVertices0n4) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 0);
    ASSERT_TRUE(dfs.marked(4));
}

TEST_F(DepthFirstSearchTests, ConnectedVerticesCountForVertex9) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 9);
    ASSERT_EQ(4, dfs.count());
}

TEST_F(DepthFirstSearchTests, ConnectedVerticesCountForVertex7) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 7);
    ASSERT_EQ(2, dfs.count());
}

TEST_F(DepthFirstSearchTests, ConnectedVerticesCountForVertex4) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 4);
    ASSERT_EQ(7, dfs.count());
}

TEST_F(DepthFirstSearchTests, ConnectedVerticesCountForVertex0) {
    using namespace algo::cpp::ds;

    DepthFirstSearch dfs(*G_, 0);
    ASSERT_EQ(7, dfs.count());
}

