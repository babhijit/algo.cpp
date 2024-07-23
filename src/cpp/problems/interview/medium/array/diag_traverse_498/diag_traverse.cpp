#include "diag_traverse.hpp"

#include <utility>

/**
 * Time Complexity: O(m*n)
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::array::diag_traverse {

    enum class DIRECTION {
        UP,
        DOWN
    };

    using COORDINATES = std::pair<int, int>;

    using Row = std::vector<int>;
    using Matrix = std::vector<Row>;

    bool traverseAndUpdateCurrent(Matrix const &mat, Row &result,
                  COORDINATES &cur, DIRECTION &dir,
                  std::size_t lastRow, std::size_t lastCol) {
        auto &[row, col] = cur;

        // we have reached the last element of the matrix
        if ((row == lastRow) and (col == lastCol)) {
            return false;
        }

        switch (dir) {
            case DIRECTION::UP:
                if (col == lastCol) {
                    dir = DIRECTION::DOWN;
                    // drop down
                    ++row;
                } else if (row == 0) {
                    dir = DIRECTION::DOWN;
                    // move right
                    ++col;
                } else {
                    // move diagonally up
                    --row;
                    ++col;
                }
                break;
            case DIRECTION::DOWN:
                if (row == lastRow) {
                    dir = DIRECTION::UP;
                    // move right
                    ++col;
                } else if (col == 0) {
                    dir = DIRECTION::UP;
                    // drop down
                    ++row;
                } else {
                    // move diagonally downwards
                    ++row;
                    --col;
                }
                break;
        }

        return true;
    }


    std::vector<int> DiagTraverse::findDiagonalOrder(std::vector<std::vector<int>> &mat) {
        auto const lastColIndex = mat[0].size() - 1;
        auto const lastRowIndex = mat.size() - 1;

        std::vector<int> result;
        result.reserve(mat.size() * mat[0].size());

        DIRECTION dir = DIRECTION::UP;
        COORDINATES current{0, 0};

        auto addToResult = [&mat, &result](auto &current) {
            auto &[x, y] = current;
            result.push_back(mat[x][y]);
        };

        do {
            addToResult(current);
        } while (traverseAndUpdateCurrent(mat, result, current, dir, lastRowIndex, lastColIndex));

        return result;
    }
}