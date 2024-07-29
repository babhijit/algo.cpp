#pragma once

#include "utils/dstypedefs.hpp"

namespace algo::interview::medium::array::number_of_islands {

    using namespace algo::cpp::ds::utils;

    class NumberOfIslands {
    public:
        int numIslands(Matrix<char>& grid);
    };

}