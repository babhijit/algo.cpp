#include <gtest/gtest.h>

#include <graph/graph.hpp>

#include <ds_loader_utils.hpp>

using namespace algo::cpp::ds::tests::utils;

/**
 * Loads Graph from txt files and simply checks they have been loaded properly or not
 */
class LoadGraphsFromFilesTest : public ::testing::Test {
protected:
    using Graph = algo::cpp::ds::Graph;

protected:
    void SetUp() override {
        GTEST_SKIP() << "Skipping as running this test takes over 6 seconds!";
    }
    
    void TearDown() override {}
};


TEST_F(LoadGraphsFromFilesTest, LoadTinyGTest) {
    using namespace algo::cpp::ds::tests::utils;
    auto G = load_graph("tinyG.txt");
    ASSERT_EQ(13, G.V());
    ASSERT_EQ(13, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadMediumGTest) {
    using namespace algo::cpp::ds::tests::utils;
    auto G = load_graph("mediumG.txt");
    ASSERT_EQ(250, G.V());
    ASSERT_EQ(1273, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadLargeGTest) {
    using namespace algo::cpp::ds::tests::utils;
    auto G = load_graph("largeG.txt");
    ASSERT_EQ(1'000'000, G.V());
    ASSERT_EQ(7'586'063, G.E());
}
