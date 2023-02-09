#include "flood_fill.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::floodfill {

    using BoolVector2D = FloodFill::Vector2D<bool>;
    using IntVector2D = FloodFill::Vector2D<int>;

    IntVector2D FloodFill::floodfill(IntVector2D &image, int sr, int sc, int color) {
        const int m = image.size();
        const int n = image[0].size();
        BoolVector2D marked = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

        int cell_color = image[sr][sc];
        if (color == cell_color) {
            return image;
        }

        // move left
        floodfill(image, marked, sr, sc - 1, cell_color, color);
        // move right
        floodfill(image, marked, sr, sc + 1, cell_color, color);
        // move up
        floodfill(image, marked, sr - 1, sc, cell_color, color);
        // move down
        floodfill(image, marked, sr + 1, sc, cell_color, color);

        return image;
    }

    void FloodFill::floodfill(IntVector2D &image, BoolVector2D &marked,
                              int sr, int sc,
                              int cell_color, int new_color) {
        // row range prev_index
        if (sr < 0 || sr >= image.size()) {
            return;
        }
        // column range prev_index
        if (sc < 0 || sc >= image[0].size()) {
            return;
        }

        // is the cell already visited
        if (marked[sr][sc])                 return;
        marked[sr][sc] = true;

        // prev_index if color is matching
        if (image[sr][sc] != cell_color)    return;
        image[sr][sc] = new_color;

        // left
        floodfill(image, marked, sr, sc - 1, cell_color, new_color);
        // right
        floodfill(image, marked, sr, sc + 1, cell_color, new_color);
        // up
        floodfill(image, marked, sr - 1, sc, cell_color, new_color);
        // down
        floodfill(image, marked, sr + 1, sc, cell_color, new_color);
    }
}
