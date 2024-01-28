#pragma once

#include <vector>
#include <cstdint>

namespace algo::interview::medium::dp::out_of_boundary_paths::detail {

    class PathFinder {
        static constexpr std::uint32_t MOD = 1e9 + 7;
        static constexpr std::int32_t PATH_FOUND = 1;
        static constexpr std::int32_t FIRST_ROW = 0;
        static constexpr std::int32_t FIRST_COLUMN = 0;

        template<typename T> using Vector2D = std::vector <std::vector<T>>;
    public:
        explicit PathFinder(std::uint32_t rows,
                            std::uint32_t columns,
                            std::uint32_t maxMoves) : ROWS{rows}, COLUMNS{columns},
                                                      MAX_MOVES{maxMoves},
                                                      LAST_ROW(rows - 1), LAST_COLUMN(columns - 1) {
        }

        [[nodiscard]] std::int32_t findPaths(std::int32_t startRow, std::int32_t startColumn) {
            auto dp = Vector2D<std::int32_t>(ROWS, std::vector<std::int32_t>(COLUMNS, 0));

            for (auto i = 0; i < MAX_MOVES; ++i) {
                findPathsForMove(dp);
            }

            return dp[startRow][startColumn];
        }

    private:
        void findPathsForMove(Vector2D<std::int32_t> &dp) {
            auto temp = Vector2D<std::int32_t>(ROWS, std::vector<std::int32_t>(COLUMNS, 0));
            for (auto r = 0; r < ROWS; ++r) {
                for (auto c = 0; c < COLUMNS; ++c) {
                    if (r == FIRST_ROW)     temp[r][c] = (temp[r][c] + PATH_FOUND) % MOD;
                    if (r < LAST_ROW)       temp[r][c] = (temp[r][c] + dp[r + 1][c]) % MOD;

                    if (r == LAST_ROW)      temp[r][c] = (temp[r][c] + PATH_FOUND) % MOD;
                    if (r > FIRST_ROW)      temp[r][c] = (temp[r][c] + dp[r - 1][c]) % MOD;

                    if (c == FIRST_COLUMN)   temp[r][c] = (temp[r][c] + PATH_FOUND) % MOD;
                    if (c < LAST_COLUMN)    temp[r][c] = (temp[r][c] + dp[r][c + 1]) % MOD;

                    if (c == LAST_COLUMN)    temp[r][c] = (temp[r][c] + PATH_FOUND) % MOD;
                    if (c > FIRST_COLUMN)   temp[r][c] = (temp[r][c] + dp[r][c - 1]) % MOD;
                }
            }
            dp.swap(temp);
        }

    private:
        const std::uint32_t MAX_MOVES;
        const std::uint32_t ROWS;
        const std::uint32_t COLUMNS;

        const std::int32_t LAST_ROW;
        const std::int32_t LAST_COLUMN;
    };

} // algo::interview::medium::dp::out_of_boundary_paths::detail
