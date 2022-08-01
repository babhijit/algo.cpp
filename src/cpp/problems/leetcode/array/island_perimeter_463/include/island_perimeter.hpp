#ifndef ALGO_CPP_ISLAND_PERIMETER_HPP
#define ALGO_CPP_ISLAND_PERIMETER_HPP

#include <vector>

namespace algo::problems::leetcode::array::island_perimeter {

    class IslandPerimeter {
    public:
        template<typename T>
        using Vector2D = std::vector<std::vector<T>>;

    public:
        int islandPerimeter(Vector2D<int>& grid);
    };

}

#endif //ALGO_CPP_ISLAND_PERIMETER_HPP
