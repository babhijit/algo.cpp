#include "island_perimeter.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::island_perimeter {

    int IslandPerimeter::islandPerimeter(Grid &grid) {

        auto const R = grid.size();
        auto const C = grid[0].size();

        int up, down, left, right;
        int perimeter = 0;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (has_land(grid[r][c])) {
                    if (r == 0) {
                        up = 0;
                    } else {
                        up = grid[r - 1][c];
                    }

                    if (c == 0) {
                        left = 0;
                    } else {
                        left = grid[r][c - 1];
                    }

                    if (r == R - 1 ) {
                        down = 0;
                    } else {
                        down = grid[r + 1][c];
                    }

                    if (c == C - 1) {
                        right = 0;
                    } else {
                        right = grid[r][c + 1];
                    }

                    perimeter += (4 - (left + right + down + up));
                }
            }
        }

        return perimeter;
    }

    bool IslandPerimeter::has_land(int cell) {
        return cell == LAND;
    }

}
