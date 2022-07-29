#include <list>
#include <vector>

#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/depth_first_paths.hpp>
#include <utils/graph_loader.hpp>

#include "stl_compare_utils.hpp"

#include "ds_resource_utils.hpp"

using namespace algo::cpp::ds::tests::utils;

class DepthFirstPathTests : public ::testing::Test {
    using Graph = algo::cpp::ds::Graph;

protected:
    std::unique_ptr<Graph> G_;

protected:
    void SetUp() override {
        algo::cpp::ds::utils::GraphLoader<Graph> loader;
        auto G = loader(get_graph_resource_path("tinyCG.txt"));
        G_ = std::make_unique<Graph>(std::move(G));
    }

    void TearDown() override { G_.reset(); }
};

TEST_F(DepthFirstPathTests, PathFromVertex0ToVertex0) {
    algo::cpp::ds::DepthFirstPaths paths(*G_, 0);
    auto path = paths.path_to(0);

    std::vector<int> expected{0};

    ASSERT_TRUE(container_value_equals(expected, path));
}

TEST_F(DepthFirstPathTests, PathFromVertex0ToVertex1) {
    algo::cpp::ds::DepthFirstPaths paths(*G_, 0);
    auto path = paths.path_to(1);

    std::vector<int> expected{0, 2, 1};

    ASSERT_TRUE(container_value_equals(expected, path));
}
