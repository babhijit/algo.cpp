#pragma once

#include <vector>

namespace algo::problems::leetcode::array::elm_in_sorted_array {

    class ElementInSortedArray {
    private:
        constexpr static double QUARTER = 0.25;

    public:
        int findSpecialInteger(std::vector<int> &arr);
    };

}