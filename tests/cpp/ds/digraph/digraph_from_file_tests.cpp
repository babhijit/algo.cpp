#include <string>

#include <gtest/gtest.h>

#include <digraph/digraph.hpp>
#include <utils/graph_loader.hpp>

#include <ds_resource_utils.hpp>

using namespace algo::cpp::ds::tests::utils;

class DigraphFromFileTests : public ::testing::Test {

protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    algo::cpp::ds::Digraph load_graph(const std::string& filepath) {
        using namespace algo::cpp::ds;
        using namespace algo::cpp::ds::utils;

        GraphLoader<Digraph> graph_loader;
        return graph_loader(get_digraph_resource_path(filepath));
    }
};


TEST_F(DigraphFromFileTests, TinyDG) {

    auto G = load_graph("tinyDG.txt");

    ASSERT_EQ(13, G.V());
    ASSERT_EQ(22, G.E());
}

TEST_F(DigraphFromFileTests, MediumDG) {

    auto G = load_graph("mediumDG.txt");

    ASSERT_EQ(50, G.V());
    ASSERT_EQ(147, G.E());
}
