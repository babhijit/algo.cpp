#include <gtest/gtest.h>

#include <flood_fill.hpp>

#include "stl_compare_utils.hpp"

using namespace algo::problems::leetcode::array::floodfill;

class FloodFillTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    template<typename T>
    using Vector2D = std::vector<std::vector<T>>;
};


TEST_F(FloodFillTests, DownRightMatrixNoChange) {
    FloodFill solution;

    Vector2D<int> input({{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    Vector2D<int> expected({{2, 2, 2}, {2, 2, 0}, {2, 0, 1}});

    auto result = solution.floodfill(input, 1, 1, 2);
    ASSERT_TRUE(container_value_equals(expected, result));
}

TEST_F(FloodFillTests, MatrixUnchanged) {
    FloodFill solution;

    Vector2D<int> input({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
    Vector2D<int> expected({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});

    auto result = solution.floodfill(input, 1, 1, 0);
    ASSERT_TRUE(container_value_equals(expected, result));
}