#ifndef ALGO_CPP_ISLAND_PERIMETER_HPP
#define ALGO_CPP_ISLAND_PERIMETER_HPP

#include <vector>
#include <utility>

namespace algo::problems::leetcode::array::island_perimeter {

    class IslandPerimeter {
    public:
        using Grid = std::vector<std::vector<int>>;
        static constexpr int LAND = 1;
    public:
        int islandPerimeter(Grid& grid);

    private:
        inline bool has_land(int cell);
    };

}

#endif //ALGO_CPP_ISLAND_PERIMETER_HPP
