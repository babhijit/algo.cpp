#ifndef ALGO_CPP_FLOODFILL_HPP
#define ALGO_CPP_FLOODFILL_HPP

#include <vector>

namespace algo::problems::leetcode::array::floodfill {

    class FloodFill {
    public:
        template<typename T>
        using Vector2D = std::vector<std::vector<T>>;

    public:
        Vector2D<int> floodfill(Vector2D<int> &image,
                                int sr,
                                int sc,
                                int color);

    private:
        void floodfill(Vector2D<int> &image, Vector2D<bool> &marked,
                       int sr,
                       int sc,
                       int cell_color,
                       int new_color);
    };

}
#endif //ALGO_CPP_FLOODFILL_HPP
