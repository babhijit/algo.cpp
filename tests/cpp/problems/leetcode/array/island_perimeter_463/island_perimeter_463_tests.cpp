#include <gtest/gtest.h>

#include <island_perimeter.hpp>

using namespace algo::problems::leetcode::array::island_perimeter;

class IslandPerimeterTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    template<typename T>
    using Vector2D = std::vector<std::vector<T>>;
};


TEST_F(IslandPerimeterTests, YellowStrips16_4x4) {
    IslandPerimeter solution;

    Vector2D<int> input({{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}});
    int expected = 16;

    auto result = solution.islandPerimeter(input);
    ASSERT_EQ(expected, result);
}

TEST_F(IslandPerimeterTests, YellowStrips4_1) {
    IslandPerimeter solution;

    Vector2D<int> input({{1}});
    int expected = 4;

    auto result = solution.islandPerimeter(input);
    ASSERT_EQ(expected, result);
}

TEST_F(IslandPerimeterTests, YellowStrips4_2x1) {
    IslandPerimeter solution;

    Vector2D<int> input({{1, 0}});
    int expected = 4;

    auto result = solution.islandPerimeter(input);
    ASSERT_EQ(expected, result);
}

