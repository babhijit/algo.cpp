#include <list>
#include <memory>
#include <vector>

#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/depth_first_paths.hpp>

#include <stl_compare_utils.hpp>

#include "graph_test_utils.hpp"

class DepthFirstPathTests : public ::testing::Test {
    using IntGraph = algo::cpp::ds::Graph<int>;

protected:
    std::unique_ptr<IntGraph> G_;

protected:
    void SetUp() override {
        auto graph_file = get_graph_resource_path("tinyCG.txt");
        auto G = algo::cpp::ds::load_graph_from_file<int>(std::move(graph_file));
        G_ = std::make_unique<IntGraph>(std::move(G));
    }

    void TearDown() override { G_.reset(); }
};

TEST_F(DepthFirstPathTests, PathFromVertex0ToVertex0) {
    algo::cpp::ds::DepthFirstPaths<int> paths(*G_, 0);
    auto path = paths.path_to(0);

    std::vector<int> expected{0};

    ASSERT_TRUE(container_value_equals(expected, path));
}

TEST_F(DepthFirstPathTests, PathFromVertex0ToVertex1) {
    algo::cpp::ds::DepthFirstPaths<int> paths(*G_, 0);
    auto path = paths.path_to(1);

    std::vector<int> expected{0, 2, 1};

    ASSERT_TRUE(container_value_equals(expected, path));
}

