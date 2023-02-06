#include "min_size_subarray_sum_sliding_window.hpp"

#include <limits>

namespace algo::problems::leetcode::array::min_size_subarray_sum {

    int MinSizeSubarraySum_SlidingWindow::minSubArrayLen(int target, std::vector<int> &nums) {
        int size = std::numeric_limits<int>::max();

        auto left = std::begin(nums);
        auto right = left;
        int sum = 0;

        while (right != std::end(nums)) {
            sum += *right++;
            while ((left != right) &&
                    greater_equal(sum, target)) {
                int subarray_size = std::distance(left, right);
                size = std::min(size, subarray_size);
                sum -= *left++;
            }
        }


        if (equal_to(size, std::numeric_limits<int>::max())) {
            return 0;
        }

        return size;
    }
}