#include <string>

#include <gtest/gtest.h>

#include <digraph/digraph.hpp>
#include <utils/graph_loader.hpp>

#include <ds_resource_utils.hpp>

#include <stl_compare_utils.hpp>

using namespace algo::cpp::ds::tests::utils;


class DigraphTests : public ::testing::Test {
protected:
    using Digraph = algo::cpp::ds::Digraph;

protected:
    std::unique_ptr<Digraph> G_;

protected:
    void SetUp() override {
        using namespace algo::cpp::ds;
        using namespace algo::cpp::ds::utils;

        GraphLoader<Digraph> graph_loader;
        auto G = graph_loader(get_digraph_resource_path("tinyDG.txt"));

        G_ = std::make_unique<Digraph>(std::move(G));
    }

    void TearDown() override {
        G_.reset();
    }
};


TEST_F(DigraphTests, SanityCheckSuccess) {
    using namespace algo::cpp::ds;

    Digraph G(1);
    ASSERT_EQ(1, G.V());
    ASSERT_EQ(0, G.E());
}

TEST_F(DigraphTests, SanityCheckFail) {
    ASSERT_THROW(Digraph(-1), std::invalid_argument);
}

TEST_F(DigraphTests, Init) {
    ASSERT_EQ(13, G_->V());
    ASSERT_EQ(22, G_->E());
}

TEST_F(DigraphTests, ValidateAdj) {
    ASSERT_TRUE(container_value_equals(std::vector<int>{5, 1}, G_-> adj(0)));

    ASSERT_TRUE(container_value_equals(std::vector<int>{4}, G_-> adj(5)));

    ASSERT_TRUE(container_value_equals(std::vector<int>{9, 4, 8, 0}, G_-> adj(6)));

    ASSERT_TRUE(container_value_equals(std::vector<int>{9}, G_-> adj(12)));
}