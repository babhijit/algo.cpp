#include "three_sum_closest.hpp"

#include <algorithm>
#include <limits>

/**
 * Space Complexity: O(N) because of sorting
 * Time Complexity: O(N^2)
 */

namespace algo::interview::medium::array::three_sum_closest {

    int ThreeSumCloset::threeSumClosest(std::vector<std::int32_t> &nums, std::int32_t target) {

        std::sort(std::begin(nums), std::end(nums));

        auto diff = std::numeric_limits<std::int32_t>::max();
        auto size = nums.size();
        auto closestSum = std::numeric_limits<std::int32_t>::max();

        for (auto i = 0; (i < size - 2) and (diff != 0); ++i) {
            auto lo = i + 1;
            auto hi = size - 1;
            while (lo < hi) {
                auto sum = nums[i] + nums[lo] + nums[hi];
                auto curDiff = target - sum;
                if (std::abs(curDiff) < std::abs(diff)) {
                    diff = curDiff;
                    closestSum = sum;
                }
                if (sum < target) {
                    ++lo;
                }  else {
                    --hi;
                }
            }
        }

        return closestSum;
    }
}