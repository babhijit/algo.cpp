#pragma once

#include <vector>

namespace algo::problems::leetcode::array::diff_btwn_1s_0s_2482 {

    using IntMatrix = std::vector<std::vector<int>>;

    class DiffBetween1sAnd0s {
    public:
        IntMatrix onesMinusZeros(IntMatrix &grid);
    };
}