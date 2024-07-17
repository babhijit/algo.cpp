#pragma once

#include <algorithm>
#include <vector>

/**
 * Space Complexity : O(m * n)
 * Time Complexity : O(m * n)
 */

namespace algo::interview::grind75::update_matrix_01::dp {


    using Matrix = std::vector<std::vector<int>>;

    class UpdateMatrix {
    public:
        Matrix operator()(Matrix &mat) {
            auto m = mat.size();
            auto n = mat[0].size();

            const int MAX_NEIGHBOURS = m * n;

            Matrix dp = mat;

            // traverse up and right
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] == 0) {
                        continue;
                    }

                    int minNeighbour = MAX_NEIGHBOURS;
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

                    int minNeighbour = MAX_NEIGHBOURS;
                    if (r < (m - 1)) {
                        minNeighbour = std::min(minNeighbour, dp[r + 1][c]);
                    }
                    if (c < (n - 1)) {
                        minNeighbour = std::min(minNeighbour, dp[r][c + 1]);
                    }

                    dp[r][c] = std::min(dp[r][c], minNeighbour + 1);
                }
            }

            return dp;
        }
    };

}