#include "longest_cont_subarr.hpp"

#include <set>
#include <utility>

namespace algo::problems::leetcode::set::longest_cont_subarr_absdiff_le_limit {

    int LongestContinousSubArray::longestSubarrary(std::vector<int> &nums, int limit) {
        std::multiset<int> window;

        int left{}, maxLength{};

        auto absRangeDiff = [](auto& window) -> int {
            auto &min = *window.begin();
            auto &max = *window.rbegin();
            return max - min;
        };

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            while (absRangeDiff(window) > limit) {
                // shrink the window by removing the leftmost element violating the limit condition
                window.erase(window.find(nums[left]));

                // move the left pointer to the right
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
