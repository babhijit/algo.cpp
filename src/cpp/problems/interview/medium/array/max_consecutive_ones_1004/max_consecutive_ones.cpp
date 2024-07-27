#include "max_consecutive_ones.hpp"

/**
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 */

namespace algo::interview::medium::array::max_consecutive_ones {

    int MaxConsecutiveOnes::longestOnes(std::vector<int> &nums, int k) {
        int left{0}, right{0};
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                --k;
            }

            // this maintains the maximum window size we can achieve
            // K can remain negative... this means that the current
            // window size corresponds to the maximum window size but
            // it's not all are consecutive 1s ... but during the iteration
            // at some point (in the past) all were consecutive 1s
            if (k < 0) {
                k += 1 - nums[left];
                ++left;
            }
        }

        return right - left;
    }

}