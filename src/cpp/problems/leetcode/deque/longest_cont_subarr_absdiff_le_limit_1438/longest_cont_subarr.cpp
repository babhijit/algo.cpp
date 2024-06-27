#include "longest_cont_subarr.hpp"

#include <deque>

namespace algo::problems::leetcode::deque::longest_cont_subarr_absdiff_le_limit {

    LongestContinousSubArray::LongestContinousSubArray()
            : lessThan_(std::less<>()),
              greaterThan_(std::greater<>()) {
    }

    int LongestContinousSubArray::longestSubarrary(std::vector<int> &nums, int limit) {
        std::deque<int> minimums; // ordered mins for the given sliding window
        std::deque<int> maximums; // ordered maxs for the given sliding window

        int left{}, maxLength{};

        auto popElementsByFilter = [](auto &deque, int value, Predicate &predicate) {
            while (not deque.empty() and predicate(deque.back(), value)) {
                deque.pop_back();
            }
        };

        for (int right = 0; right < nums.size(); ++right) {
            auto &element = nums[right];

            // maintain maximums in decreasing order
            popElementsByFilter(maximums, element, lessThan_);
            maximums.push_back(element);

            // maintain minimums in increasing order
            popElementsByFilter(minimums, element, greaterThan_);
            minimums.push_back(element);

            auto absDiff = [](const auto& max, const auto& min) {
                return max - min;
            };

            // check if the current window exceeds the limit
            while(absDiff(maximums.front(), minimums.front()) > limit) {
                // remove elements that are not in current window
                if (maximums.front() == nums[left]) {
                    maximums.pop_front();
                }

                if (minimums.front() == nums[left]) {
                    minimums.pop_front();
                }

                // move the window to the right
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
