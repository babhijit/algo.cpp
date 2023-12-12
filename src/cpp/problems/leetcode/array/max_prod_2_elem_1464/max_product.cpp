#include "max_product.hpp"

#include <cassert>
#include <functional>

namespace algo::problems::leetcode::array::max_product_1464 {

    int MaxProduct::maxProduct(std::vector<int> &nums) {

        assert(nums.size() >= 2 && "nums.size() must be >= 2");

        auto it = std::begin(nums);
        auto biggest = *it;
        auto second_biggest = *it;

        while (++it != std::end(nums)) {
            if (biggest <= *it) {
                second_biggest = biggest;
                biggest = *it;
            } else if (second_biggest < *it) {
                second_biggest = *it;
            }
        }

        return std::multiplies()(biggest - 1, second_biggest - 1);
    }

}