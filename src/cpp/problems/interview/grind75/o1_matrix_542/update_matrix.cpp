#include "update_matrix.hpp"

/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */

namespace algo::interview::grind75::update_matrix_01 {

    Matrix<int> UpdateMatrix::updateMatrix(Matrix<int> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        Matrix<int> dp;
        for (auto& row: mat) {
            dp.emplace_back(row.begin(), row.end());
        }

        // first traverse up and right
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0) {
                    continue;
                }

                int minNeighbour = m * n;
                if (r > 0) {
                    minNeighbour = std::min(minNeighbour, dp[r - 1][c]);
                }
                if (c > 0) {
                    minNeighbour = std::min(minNeighbour, dp[r][c - 1]);
                }

                dp[r][c] = minNeighbour + 1;
            }
        }

        // traverse down and left
        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (dp[r][c] == 0) {
                    continue;
                }

                int minNeighbour = m * n;
                if (r < m - 1) {
                    minNeighbour = std::min(minNeighbour, dp[r + 1][c]);
                }
                if (c < n - 1) {
                    minNeighbour = std::min(minNeighbour, dp[r][c + 1]);
                }

                dp[r][c] = std::min(minNeighbour + 1, dp[r][c]);
            }
        }

        return dp;
    }
}