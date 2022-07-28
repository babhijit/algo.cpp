#include <memory>

#include <gtest/gtest.h>

#include <graph/graph.hpp>
#include <graph/breadth_first_paths.hpp>

#include "stl_compare_utils.hpp"
#include "graph_test_utils.hpp"

class BreadthFirstPathsTests : public ::testing::Test {
protected:
    std::unique_ptr<algo::cpp::ds::Graph> G_;

protected:
    void SetUp() override {
        using namespace algo::cpp::ds;
        auto graph_file = get_graph_resource_path("tinyCG.txt");
        auto G = load_graph_from_file(std::move(graph_file));
        G_ = std::make_unique<Graph>(std::move(G));
    }

    void TearDown() override {
        G_.reset();
    }
};

TEST_F(BreadthFirstPathsTests, PathFromVertex0ToVertex0) {
    algo::cpp::ds::BreadthFirstPaths paths(*G_, 0);
    auto path = paths.path_to(0);

    std::vector<int> expected{0};

    ASSERT_TRUE(container_value_equals(expected, path));
}


TEST_F(BreadthFirstPathsTests, PathFromVertex0ToVertex1) {
    algo::cpp::ds::BreadthFirstPaths paths(*G_, 0);
    auto path = paths.path_to(1);

    std::vector<int> expected{0, 1};

    ASSERT_TRUE(container_value_equals(expected, path));
}

TEST_F(BreadthFirstPathsTests, PathFromVertex0ToVertex3) {
    algo::cpp::ds::BreadthFirstPaths paths(*G_, 0);
    auto path = paths.path_to(3);

    std::vector<int> expected{0, 5, 3};

    ASSERT_TRUE(container_value_equals(expected, path));
}
