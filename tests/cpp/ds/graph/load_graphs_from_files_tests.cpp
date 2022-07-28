#include <gtest/gtest.h>

#include <graph/graph.hpp>

#include "graph_test_utils.hpp"

/**
 * Loads Graph from txt files and simply checks they have been loaded properly or not
 */
class LoadGraphsFromFilesTest : public ::testing::Test {
protected:
    using IntGraph = algo::cpp::ds::Graph<int>;
    
protected:
    void SetUp() override {}
    
    void TearDown() override {}
};


TEST_F(LoadGraphsFromFilesTest, LoadTinyGTest) {
    auto tinyGPath = get_graph_resource_path("tinyG.txt");
    IntGraph G = algo::cpp::ds::load_graph_from_file<int>(tinyGPath);
    ASSERT_EQ(13, G.V());
    ASSERT_EQ(13, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadMediumGTest) {
    auto mediumGPath = get_graph_resource_path("mediumG.txt");
    IntGraph G = algo::cpp::ds::load_graph_from_file<int>(mediumGPath);
    ASSERT_EQ(250, G.V());
    ASSERT_EQ(1273, G.E());
}
