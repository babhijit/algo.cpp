#pragma once

#include <algorithm>
#include <queue>
#include <vector>

/**
 * Space Complexity : O(m * n)
 * Time Complexity : O(m * n)
 */

namespace algo::interview::grind75::update_matrix_01::bfs {

    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    class UpdateMatrix {
    private:
        inline static const std::vector RIGHT{0, 1};
        inline static const std::vector LEFT{0, -1};
        inline static const std::vector UP{1, 0};
        inline static const std::vector DOWN{-1, 0};

        inline static const Matrix<int> directions{RIGHT, DOWN, LEFT, UP};

        enum Dimension {
            ROW,
            COLUMN
        };

    public:
        Matrix<int> operator()(Matrix<int> &mat) {
            const int M = mat.size();
            const int N = mat[0].size();

            Matrix<int> distance(M, std::vector<int>(N, 0));
            Matrix<bool> visited(M, std::vector<bool>(N, false));
            std::queue<std::vector<int>> bfs;

            for (int r = 0; r < M; r++) {
                for (int c = 0; c < N; c++) {
                    distance[r][c] = mat[r][c];
                    if (distance[r][c] == 0) {
                        bfs.push({r, c, 0});
                        visited[r][c] = true;
                    }
                }
            }

            auto isValidRow = [&M](auto r) {
                return (0 <= r) and (r < M);
            };

            auto isValidCol = [&N](auto c) {
                return (0 <= c) and (c < N);
            };

            auto isValidCell = [&isValidRow, &isValidCol](auto r, auto c) {
                return isValidRow(r) and isValidCol(c);
            };

            while (not bfs.empty()) {
                auto cur = bfs.front();
                bfs.pop();

                auto steps = cur[2];

                for (auto &direction: directions) {
                    auto nextRow =  cur[ROW] + direction[ROW];
                    auto nextCol = cur[COLUMN] + direction[COLUMN];

                    if (isValidCell(nextRow, nextCol) and not visited[nextRow][nextCol]) {
                        visited[nextRow][nextCol] = true;
                        distance[nextRow][nextCol] = steps + 1;
                        bfs.push({nextRow, nextCol, steps + 1});
                    }
                }
            }

            return distance;
        }
    };
}