#include <array>
#include <random>
#include <vector>

#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <utils/graph_loader.hpp>

#include <ds_loader_utils.hpp>

using namespace algo::cpp::ds;
using namespace algo::cpp::ds::tests::utils;

/*
 * To run this test ensure that the IDE sets the current working directory to "resources" directory
 * This test specifically runs on tinyG.txt and all the tests are hardwired to this file.
 */
class GraphFromFileTests : public ::testing::Test {
protected :
    std::unique_ptr<Graph> G_;
    int VERTICES;
    int EDGES;
    int SELF_LOOPS_COUNT;
    std::size_t MAX_DEGREE;
    std::vector<int> VERTEX_DEGREE;
    std::vector<std::vector<int>> ADJ;

protected:
    void SetUp() override {
        VERTICES = 13;

        ADJ.push_back(std::vector<int>{5, 1, 2, 6});
        ADJ.push_back(std::vector<int>{0});
        ADJ.push_back(std::vector<int>{0});
        ADJ.push_back(std::vector<int>{4, 5});
        ADJ.push_back(std::vector<int>{3, 6, 5});
        ADJ.push_back(std::vector<int>{0, 4, 3});
        ADJ.push_back(std::vector<int>{4, 0});
        ADJ.push_back(std::vector<int>{8});
        ADJ.push_back(std::vector<int>{7});
        ADJ.push_back(std::vector<int>{12, 10, 11});
        ADJ.push_back(std::vector<int>{9});
        ADJ.push_back(std::vector<int>{12, 9});
        ADJ.push_back(std::vector<int>{9, 11});

        VERTEX_DEGREE.push_back(4);
        VERTEX_DEGREE.push_back(1);
        VERTEX_DEGREE.push_back(1);
        VERTEX_DEGREE.push_back(2);
        VERTEX_DEGREE.push_back(3);
        VERTEX_DEGREE.push_back(3);
        VERTEX_DEGREE.push_back(2);
        VERTEX_DEGREE.push_back(1);
        VERTEX_DEGREE.push_back(1);
        VERTEX_DEGREE.push_back(3);
        VERTEX_DEGREE.push_back(1);
        VERTEX_DEGREE.push_back(2);
        VERTEX_DEGREE.push_back(2);

        SELF_LOOPS_COUNT = 0;
        EDGES = 13;
        MAX_DEGREE = 4;

        load_graph_from_resource();
    }

    void TearDown() override {
        G_.reset(nullptr);
    }

    int get_random_vertex() {
        std::random_device rd;
        std::mt19937 rand_gen(rd());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 12);
        return dist(rand_gen);
    }

private:
    void load_graph_from_resource() {
        using namespace algo::cpp::ds::tests::utils;
        auto G = load_graph("tinyG.txt");
        G_ = std::make_unique<Graph>(std::move(G));
    }
};

TEST_F(GraphFromFileTests, GraphVertices) {
    ASSERT_EQ(VERTICES, G_->V());
}

TEST_F(GraphFromFileTests, GraphEdges) {
    ASSERT_EQ(EDGES, G_->E());
}

TEST_F(GraphFromFileTests, GraphMaxDegree) {
    ASSERT_EQ(MAX_DEGREE, G_->max_degree());
}

TEST_F(GraphFromFileTests, GraphDegreeOfAnyVertex) {
    const int VERTEX_NO = get_random_vertex();
    ASSERT_EQ(VERTEX_DEGREE[VERTEX_NO], G_->degree(VERTEX_NO));
}

TEST_F(GraphFromFileTests, GraphSelfLoopCount) {
    ASSERT_EQ(SELF_LOOPS_COUNT, G_->self_loops_count());
}

TEST_F(GraphFromFileTests, GraphAdjCheck) {
    int v = get_random_vertex();
    auto &adj = G_->adj(v);

    auto adj_itr = std::rbegin(ADJ[v]);
    for (auto it = std::begin(adj); it != std::end(adj); ++it) {
        ASSERT_EQ(*adj_itr++, *it);
    }
}
