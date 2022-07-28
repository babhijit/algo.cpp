#include <gtest/gtest.h>

#include <graph/graph.hpp>

#include "graph_test_utils.hpp"

/**
 * Loads Graph from txt files and simply checks they have been loaded properly or not
 */
class LoadGraphsFromFilesTest : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;
    
protected:
    void SetUp() override {}
    
    void TearDown() override {}
};


TEST_F(LoadGraphsFromFilesTest, LoadTinyGTest) {
    auto tinyGPath = get_graph_resource_path("tinyG.txt");
    Graph G = algo::cpp::ds::load_graph_from_file(std::move(tinyGPath));
    ASSERT_EQ(13, G.V());
    ASSERT_EQ(13, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadMediumGTest) {
    auto mediumGPath = get_graph_resource_path("mediumG.txt");
    Graph G = algo::cpp::ds::load_graph_from_file(std::move(mediumGPath));
    ASSERT_EQ(250, G.V());
    ASSERT_EQ(1273, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadLargeGTest) {
    auto mediumGPath = get_graph_resource_path("largeG.txt");
    Graph G = algo::cpp::ds::load_graph_from_file(std::move(mediumGPath));
    ASSERT_EQ(1'000'000, G.V());
    ASSERT_EQ(7'586'063, G.E());
}
