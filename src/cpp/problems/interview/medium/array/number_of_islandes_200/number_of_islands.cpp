#include "number_of_islands.hpp"

#include <utils/not_implemented.hpp>

namespace algo::interview::medium::array::number_of_islands {

    constexpr char LAND{'1'};
    [[maybe_unused]] constexpr char WATER{'0'};

    bool isLand(char elementType) {
        return elementType == LAND;
    }

    class Impl {
    private:
        Matrix<char> &grid_;
        int count_{0};

        Matrix<bool> visited_;
        const int M; // ROWS
        const int N; // COLUMNS
    public:
        explicit Impl(Matrix<char> &grid) : grid_(grid), M(grid.size()), N(grid[0].size()) {
            visited_ = Matrix<bool>(M, std::vector<bool>(N, false));

            for (int r = 0; r < M; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (not visited_[r][c]) {
                        dfs(r, c);
                    }
                }
            }
        }

        [[nodiscard]] int count() const {
            return count_;
        }

    private:
        void dfs(int r, int c) {
            if (not isLand(grid_[r][c])) {
                visited_[r][c] = true;
                return;
            }

            markLandRegion(r, c);

            // found new land
            ++count_;
        }

        void markLandRegion(int r, int c) {
            if (visited_[r][c]) {
                return;
            }

            visited_[r][c] = true;

            if (not isLand(grid_[r][c])) {
                return;
            }

            // move up
            if (r > 0) {
                markLandRegion(r - 1, c);
            }

            // move down
            if (r < (M - 1)) {
                markLandRegion(r + 1, c);
            }

            // move left
            if (c > 0) {
                markLandRegion(r, c - 1);
            }
            // move right
            if (c < (N - 1)) {
                markLandRegion(r, c + 1);
            }
        }
    };

    int NumberOfIslands::numIslands(Matrix<char> &grid) {
        Impl impl(grid);
        return impl.count();
    }
}