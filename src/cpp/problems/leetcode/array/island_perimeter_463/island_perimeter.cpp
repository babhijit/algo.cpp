#include "island_perimeter.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::island_perimeter {

    int IslandPerimeter::islandPerimeter(Grid &grid) {

        rows = static_cast<int>(grid.size());
        columns = static_cast<int>(grid[0].size());

        int perimeter = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                if (has_land(grid[r][c])) {
                    auto neighbouring_lands = get_neighbouring_land(grid, r, c - 1) +
                                              get_neighbouring_land(grid, r, c + 1) +
                                              get_neighbouring_land(grid, r - 1, c) +
                                              get_neighbouring_land(grid, r + 1, c);
                    perimeter += (4 - neighbouring_lands);
                }
            }
        }

        return perimeter;
    }

    bool IslandPerimeter::has_land(int cell) {
        return cell == LAND;
    }

    int IslandPerimeter::get_neighbouring_land(IslandPerimeter::Grid &grid, int r, int c) {
        if ((r < 0) || (r >= rows))     return 0;
        if ((c < 0) || (c >= columns))  return 0;

        return grid[r][c];
    }

}
