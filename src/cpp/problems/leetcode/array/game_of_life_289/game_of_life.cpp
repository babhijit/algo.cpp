#include "game_of_life.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::game_of_life {

    void GameOfLife::gameOfLife(Matrix& board) {
        const auto ROWS = board.size();
        const auto COLUMNS = board[0].size();

        Matrix original(board);
        for (int row=0; row<ROWS; ++row) {
            for(int column=0; column<COLUMNS; ++column) {
                board[row][column] = getNextLifeState(original, row, column);
            }
        }
    }

    int GameOfLife::getNextLifeState(const Matrix &board, const int row, const int column) {
        int currentState = board[row][column];

        int aliveNeighbours = getAliveNeighbours(board, row, column);

        if (currentState == ALIVE) {
            if (isUnderPopulation(aliveNeighbours) || isOverPopulation(aliveNeighbours)) {
                return DEAD;
            }
        } else {
            if (canBeReproduced(aliveNeighbours)) {
                return ALIVE;
            }
        }

        return currentState;
    }

    int GameOfLife::getAliveNeighbours(const Matrix &board, const int row, const int column) {
        int aliveNeighbours = 0;

        const int LEFT = column - 1;
        const int RIGHT = column + 1;
        const int UP = row - 1;
        const int DOWN = row + 1;

        aliveNeighbours += getCurrentLifeState(board, row, LEFT);
        aliveNeighbours += getCurrentLifeState(board, row, RIGHT);
        aliveNeighbours += getCurrentLifeState(board, UP, column);
        aliveNeighbours += getCurrentLifeState(board, UP, LEFT);
        aliveNeighbours += getCurrentLifeState(board, UP, RIGHT);
        aliveNeighbours += getCurrentLifeState(board, DOWN, column);
        aliveNeighbours += getCurrentLifeState(board, DOWN, LEFT);
        aliveNeighbours += getCurrentLifeState(board, DOWN, RIGHT);

        return aliveNeighbours;
    }

    int GameOfLife::getCurrentLifeState(const Matrix& board, const int row, const int column) {
        if((row >= 0) && (row < board.size())) {
            if ((column >= 0) && (column < board[row].size())) {
                return board[row][column];
            }
        }
        return 0;
    }
}