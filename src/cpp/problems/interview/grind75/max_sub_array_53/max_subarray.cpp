#include "max_subarray.hpp"

#include <algorithm>

/**
 * Time Complexity: O(N)
 * Space Complexity: 1
 */

namespace algo::interview::grind75::max_subarray {

    int MaxSubArray::maxSubArray(std::vector<int> &nums) {
        int maxSum {nums[0]};
        int runningSum {nums[0]};

        for (auto i = 1; i < nums.size(); ++i) {
            runningSum = std::max(runningSum + nums[i], nums[i]);
            maxSum = std::max(maxSum, runningSum);
        }

        return maxSum;
    }
}