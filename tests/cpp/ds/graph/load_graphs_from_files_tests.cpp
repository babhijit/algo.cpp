#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <utils/graph_loader.hpp>

#include "ds_resource_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

/**
 * Loads Graph from txt files and simply checks they have been loaded properly or not
 */
class LoadGraphsFromFilesTest : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;

    algo::cpp::ds::utils::GraphLoader<Graph> graph_loader;
    
protected:
    void SetUp() override {
        GTEST_SKIP() << "Skipping as running this test takes over 6 seconds!";
    }
    
    void TearDown() override {}
};


TEST_F(LoadGraphsFromFilesTest, LoadTinyGTest) {
    Graph G = graph_loader(get_graph_resource_path("tinyG.txt"));
    ASSERT_EQ(13, G.V());
    ASSERT_EQ(13, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadMediumGTest) {
    Graph G = graph_loader(get_graph_resource_path("mediumG.txt"));
    ASSERT_EQ(250, G.V());
    ASSERT_EQ(1273, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadLargeGTest) {
    Graph G = graph_loader(get_graph_resource_path("largeG.txt"));
    ASSERT_EQ(1'000'000, G.V());
    ASSERT_EQ(7'586'063, G.E());
}
