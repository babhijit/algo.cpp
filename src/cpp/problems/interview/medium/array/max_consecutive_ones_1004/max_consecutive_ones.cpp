#include "max_consecutive_ones.hpp"

/**
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 */

namespace algo::interview::medium::array::max_consecutive_ones {

    int MaxConsecutiveOnes::longestOnes(std::vector<int> &nums, int k) {
        int flipsRemaining{k};
        int left{0}, right{0}, sum{0};
        int maxSum{0};

        while (right < nums.size()) {
            maxSum = std::max(maxSum, sum);

            // got consecutive 1s ...
            if (nums[right] == 1) {
                ++sum;
                ++right;
                continue;
            }

            // have we got enough Ks to flip 0 to 1
            if (flipsRemaining > 0) {
                --flipsRemaining;
                ++sum;
                ++right;
                continue;
            }

            // not enough Ks.. so slide our window
            if (left < right) {
                if (nums[left] == 1) {
                    --sum;
                } else {
                    // check if we can get back some of the K
                    if (flipsRemaining < k) {
                        ++flipsRemaining;
                        --sum;
                    }
                }
                ++left;
            } else {
                // we can't shrink the window any further... so move the right pointer
                ++right;
            }
        }

        return std::max(maxSum, sum);;
    }

}