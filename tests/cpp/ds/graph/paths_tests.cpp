#include <memory>

#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/paths.hpp>

#include "graph_test_utils.hpp"

class PathsTests : public ::testing::Test {
protected:
    using IntGraph = algo::cpp::ds::Graph<int>;
    std::unique_ptr<IntGraph> G_;

protected:
    void SetUp() override {
        auto graph_file = get_graph_resource_path("tinyG.txt");
        auto G = algo::cpp::ds::load_graph_from_file<int>(graph_file);
        G_ = std::make_unique<IntGraph>(std::move(G));
    }

    void TearDown() override {
        G_.reset();
    }
};

TEST_F(PathsTests, NotConnectedTestForVertices0n7) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 0);
    ASSERT_FALSE(paths.connected(7));
}

TEST_F(PathsTests, NotConnectedTestForVertices0n9) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 0);
    ASSERT_FALSE(paths.connected(9));
}

TEST_F(PathsTests, ConnectedTestForVertices9n11) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 9);
    ASSERT_TRUE(paths.connected(11));
}

TEST_F(PathsTests, ConnectedTestForVertices9n10) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 9);
    ASSERT_TRUE(paths.connected(10));
}

TEST_F(PathsTests, ConnectedTestForVertices0n4) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 0);
    ASSERT_TRUE(paths.connected(4));
}

TEST_F(PathsTests, ConnectedVerticesCountForVertex9) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 9);
    ASSERT_EQ(4, paths.count());
}

TEST_F(PathsTests, ConnectedVerticesCountForVertex7) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 7);
    ASSERT_EQ(2, paths.count());
}

TEST_F(PathsTests, ConnectedVerticesCountForVertex4) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 4);
    ASSERT_EQ(7, paths.count());
}

TEST_F(PathsTests, ConnectedVerticesCountForVertex0) {
    using namespace algo::cpp::ds;

    Paths<int> paths(*G_, 0);
    ASSERT_EQ(7, paths.count());
}

