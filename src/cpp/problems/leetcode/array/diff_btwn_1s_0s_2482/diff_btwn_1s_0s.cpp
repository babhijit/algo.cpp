#include "diff_btwn_1s_0s.hpp"


namespace algo::problems::leetcode::array::diff_btwn_1s_0s_2482 {

    IntMatrix DiffBetween1sAnd0s::onesMinusZeros(IntMatrix &grid) {
        IntMatrix result(grid.size(), std::vector<int>(grid[0].size(), 0));

        auto const M = grid.size();
        auto const N = grid[0].size();

        std::vector<int> rowDiff(M, 0);
        std::vector<int> colDiff(N, 0);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) {
                    ++rowDiff[i];
                    ++colDiff[j];
                } else {
                    --rowDiff[i];
                    --colDiff[j];
                }
            }
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                result[i][j] = rowDiff[i] + colDiff[j];
            }
        }

        return result;
    }
}