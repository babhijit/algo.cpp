#ifndef ALGO_CPP_GAME_OF_LIFE_HPP
#define ALGO_CPP_GAME_OF_LIFE_HPP

#include <vector>

namespace algo::problems::leetcode::array::game_of_life {

    using Matrix = std::vector<std::vector<int>>;

    class GameOfLife {
    private:
        const int DEAD = 0;
        const int ALIVE = 1;

    public:
        void gameOfLife(Matrix &board);

    private:
        int getNextLifeState(const Matrix &board, const int row, const int column);

        int getCurrentLifeState(const Matrix& board, const int row, const int column);

        int getAliveNeighbours(const Matrix &board, const int row, const int column);

        inline bool isUnderPopulation(const int aliveNeighbours) const { return aliveNeighbours < 2; }

        inline bool isOverPopulation(const int aliveNeighbours) const { return aliveNeighbours > 3; }

        inline bool canBeReproduced(const int aliveNeighbours) const { return aliveNeighbours == 3; }
    };
}

#endif //ALGO_CPP_GAME_OF_LIFE_HPP
