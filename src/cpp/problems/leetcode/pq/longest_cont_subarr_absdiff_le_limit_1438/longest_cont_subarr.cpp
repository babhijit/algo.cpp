#include "longest_cont_subarr.hpp"

#include <queue>
#include <utility>

namespace algo::problems::leetcode::pq::longest_cont_subarr_absdiff_le_limit {

    int LongestContinousSubArray::longestSubarrary(std::vector<int> &nums, int limit) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        std::priority_queue<std::pair<int, int>,
                std::vector<std::pair<int, int>>,
                std::greater<>>
                minHeap;

        int left{}, maxLength{};

        for(int right = 0; right < nums.size(); ++right) {
            maxHeap.emplace(nums[right], right);
            minHeap.emplace(nums[right], right);

            while ((maxHeap.top().first - minHeap.top().first) > limit) {
                // move the left pointer of the sliding window to the right till our condition is met
                // this shrinks our sliding window to only the elements whose abs diff is within limit
                left = std::min(maxHeap.top().second, minHeap.top().second) + 1;

                // only keep the elements that are inside our current sliding window
                while (maxHeap.top().second < left)     maxHeap.pop();
                while (minHeap.top().second < left)     minHeap.pop();
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
