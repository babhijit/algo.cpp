#include <array>
#include <stdexcept>

#include <gtest/gtest.h>

#include <graph/graph.hpp>

class GraphTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(GraphTests, InitSuccess) {
    algo::cpp::ds::Graph<int> G(0);
    ASSERT_EQ(0, G.V());
    ASSERT_EQ(0, G.E());
}

TEST_F(GraphTests, InitFail) {
    using namespace algo::cpp::ds;
    ASSERT_THROW(Graph<int>(-1), std::invalid_argument);
}

TEST_F(GraphTests, Graph_5V) {
    using namespace algo::cpp::ds;
    constexpr int VERTICES = 5;
    Graph<int> G(VERTICES);

    ASSERT_EQ(VERTICES, G.V());
}