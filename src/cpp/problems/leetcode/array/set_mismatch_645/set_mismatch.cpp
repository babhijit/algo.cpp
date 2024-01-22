#include "set_mismatch.hpp"

#include <cassert>

namespace algo::problems::leetcode::array::set_mismatch {

    std::vector<int> SetMismatch::findErrorNums(std::vector<int> &nums) {
        assert(nums.size() > 1 and "nums must have at least two elements");

        std::vector<int> hash(nums.size() + 1, 0);

        int duplicate{};
        for (auto n: nums) {
            if (++hash[n] == 2) {
                duplicate = n;
            }
        }

        for (int i = 1; i < nums.size() + 1; ++i) {
            if (not hash[i]) {
                return {duplicate, i};
            }
        }

        throw std::runtime_error("Unreachable");
    }

} // algo::problems::leetcode::array::set_mismatch