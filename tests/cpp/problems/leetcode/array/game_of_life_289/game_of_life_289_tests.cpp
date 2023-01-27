#include <gtest/gtest.h>

#include <game_of_life.hpp>

using namespace algo::problems::leetcode::array::game_of_life;

class GameOfLifeTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(GameOfLifeTests, Board_2x2) {
    GameOfLife solution;

    Matrix board({{1, 1}, {1, 0}});
    Matrix expected({{1, 1}, {1, 1}});

    solution.gameOfLife(board);
    ASSERT_EQ(expected, board);
}

TEST_F(GameOfLifeTests, Board_4x3) {
    GameOfLife solution;

    Matrix board({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}});
    Matrix expected({{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}});

    solution.gameOfLife(board);
    ASSERT_EQ(expected, board);
}

