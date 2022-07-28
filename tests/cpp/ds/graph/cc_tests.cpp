#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include <graph/cc.hpp>

#include <stl_compare_utils.hpp>
#include "graph_test_utils.hpp"

class CCTests : public ::testing::Test {

    using Graph = algo::cpp::ds::Graph;
    using CC = algo::cpp::ds::CC;

protected:
    const std::string graph_filename = "tinyG.txt";
    std::unique_ptr<Graph> G_;
    std::unique_ptr<CC> cc_;


protected:
    void SetUp() override {
        auto G = algo::cpp::ds::load_graph_from_file(get_graph_resource_path(graph_filename));
        G_ = std::make_unique<Graph>(std::move(G));
        cc_ = std::make_unique<CC>(*G_);
    }

    void TearDown() override {
        G_.reset();
    }
};


TEST_F(CCTests, CheckComponents) {
    ASSERT_EQ(3, cc_->count());
}

TEST_F(CCTests, VerifyComponent2) {
    std::vector<int> expected{9, 10, 11, 12};
    auto components = cc_->components();

    ASSERT_TRUE(container_value_equals(expected, components[2]));
}