#pragma once

#include <vector>
#include <cstdint>

namespace algo::problems::leetcode::array::out_of_boundary_paths::detail {

    class PathFinder {
        static constexpr std::int32_t YET_TO_COMPUTE = -1;
        static constexpr std::int32_t PATH_NOT_FOUND = 0;
        static constexpr std::int32_t PATH_FOUND = 1;
        static constexpr std::uint32_t MOD = 1e9 + 7;
        template<typename T> using Vector2D = std::vector <std::vector<T>>;
        template<typename T> using Vector3D = std::vector<Vector2D<T>>;
    public:
        explicit PathFinder(std::uint32_t rows,
                            std::uint32_t columns,
                            std::uint32_t maxMoves) : ROWS{rows},
                                                      COLUMNS{columns},
                                                      MAX_MOVES{maxMoves},
                                                      cache_(rows,
                                                             {columns,
                                                              std::vector<int>(maxMoves + 1, YET_TO_COMPUTE)}) {
        }

        [[nodiscard]] std::int32_t findPaths(int startRow, int startColumn) {
            return findPaths(MAX_MOVES, startRow, startColumn);
        }

    private:

        [[nodiscard]] std::int32_t findPaths(std::uint32_t movesLeft, std::int32_t r, std::int32_t c) {
            if (not insideBounds(r, c)) {
                // this step takes it out of the boundaries
                return PATH_FOUND;
            }

            if (not movesLeft) {
                return PATH_NOT_FOUND;
            }

            auto &movesTaken = cache_[r][c][movesLeft];

            // The move is made and is inside bounds
            --movesLeft;

            if (not isComputed(movesTaken)) {
                auto up = r - 1;
                auto down = r + 1;
                auto left = c - 1;
                auto right = c + 1;

                movesTaken = findPaths(movesLeft, r, left) % MOD +
                             findPaths(movesLeft, r, right) % MOD +
                             findPaths(movesLeft, up, c) % MOD +
                             findPaths(movesLeft, down, c) % MOD;
                movesTaken %= MOD;
            }

            return movesTaken;
        }

        [[nodiscard]] bool insideBounds(int r, int c) const {
            if ((r == ROWS) or (c == COLUMNS) or (r < 0) or (c < 0)) {
                return false;
            }
            return true;
        }

        static inline bool isComputed(const std::int32_t movesTaken) { return movesTaken != YET_TO_COMPUTE; };

    private:
        Vector3D<int> cache_;
        const std::uint32_t MAX_MOVES;
        const std::uint32_t ROWS;
        const std::uint32_t COLUMNS;
    };

} // algo::interview::medium::dp::out_of_boundary_paths::detail
