#include <array>
#include <memory>
#include <random>
#include <stdexcept>
#include <vector>

#include <gtest/gtest.h>

#include <graph/graph.hpp>

using namespace algo::cpp::ds;

class GraphTests : public ::testing::Test {

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
        G_ = std::make_unique<Graph>(VERTICES);

        ADJ.emplace_back(std::vector<int>{5, 1, 2, 6});
        ADJ.emplace_back(std::vector<int>{0});
        ADJ.emplace_back(std::vector<int>{0});
        ADJ.emplace_back(std::vector<int>{4, 5});
        ADJ.emplace_back(std::vector<int>{3, 6, 5});
        ADJ.emplace_back(std::vector<int>{0, 4, 3});
        ADJ.emplace_back(std::vector<int>{4, 0});
        ADJ.emplace_back(std::vector<int>{8});
        ADJ.emplace_back(std::vector<int>{7});
        ADJ.emplace_back(std::vector<int>{12, 10, 11});
        ADJ.emplace_back(std::vector<int>{9});
        ADJ.emplace_back(std::vector<int>{12, 9});
        ADJ.emplace_back(std::vector<int>{9, 11});


        std::vector<std::pair<int, int>> edges;
        edges.emplace_back(0, 5);
        edges.emplace_back(4, 3);
        edges.emplace_back(0, 1);
        edges.emplace_back(9, 12);
        edges.emplace_back(6, 4);
        edges.emplace_back(5, 4);
        edges.emplace_back(0, 2);
        edges.emplace_back(11, 12);
        edges.emplace_back(9, 10);
        edges.emplace_back(0, 6);
        edges.emplace_back(7, 8);
        edges.emplace_back(9, 11);
        edges.emplace_back(5, 3);

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

        EDGES = 0;
        for (auto &edge: edges) {
            G_->add_edge(edge.first, edge.second);
            ++EDGES;
        }
        MAX_DEGREE = 4;
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
};


TEST_F(GraphTests, InitSuccess) {
    algo::cpp::ds::Graph G(0);
    ASSERT_EQ(0, G.V());
    ASSERT_EQ(0, G.E());
}

TEST_F(GraphTests, GraphCopy) {
    Graph G_copy = *G_;
    ASSERT_STREQ(G_->str().c_str(), G_copy.str().c_str());
}

TEST_F(GraphTests, InitFail) {
    using namespace algo::cpp::ds;
    ASSERT_THROW(Graph(-1), std::invalid_argument);
}

TEST_F(GraphTests, GraphVertices) {
    ASSERT_EQ(VERTICES, G_->V());
}

TEST_F(GraphTests, GraphEdges) {
    ASSERT_EQ(EDGES, G_->E());
}

TEST_F(GraphTests, GraphMaxDegree) {
    ASSERT_EQ(MAX_DEGREE, G_->max_degree());
}

TEST_F(GraphTests, GraphDegreeOfAnyVertex) {
    const int VERTEX_NO = get_random_vertex();
    ASSERT_EQ(VERTEX_DEGREE[VERTEX_NO], G_->degree(VERTEX_NO));
}

TEST_F(GraphTests, GraphSelfLoopCount) {
    ASSERT_EQ(SELF_LOOPS_COUNT, G_->self_loops_count());
}

TEST_F(GraphTests, GraphAdjCheck) {
    int v = get_random_vertex();
    auto &adj = G_->adj(v);

    auto adj_itr = std::rbegin(ADJ[v]);
    for (auto it = std::begin(adj); it != std::end(adj); ++it) {
        ASSERT_EQ(*adj_itr++, *it);
    }
}
