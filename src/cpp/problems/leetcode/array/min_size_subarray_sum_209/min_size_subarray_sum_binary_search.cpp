#include "min_size_subarray_sum_binary_search.hpp"

#include <functional>
#include <numeric>
#include <limits>
#include <algorithm>


namespace algo::problems::leetcode::array::min_size_subarray_sum {

    std::vector<int> MinSizeSubarraySum_BinarySearch::get_prefix_sum(const std::vector<int> &nums) {
        std::vector<int> prefix_sum(nums.size() + 1);

        auto prefix_itr = std::begin(prefix_sum);
        *prefix_itr = 0;

        // for ease of calculation, prefix_sum's sums are mapped to next element of the corresponding vector nums
        ++prefix_itr;

        std::partial_sum(std::begin(nums), std::end(nums), prefix_itr, std::plus<>());
        return prefix_sum;
    }

    int MinSizeSubarraySum_BinarySearch::minSubArrayLen(int target, std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int min_subarray_size = std::numeric_limits<int>::max();

        auto prefix_sum = get_prefix_sum(nums);
        auto ps_start = std::begin(prefix_sum);
        auto ps_end = std::end(prefix_sum);


        // remember that the prefix sum starts from index 1
        // to help ease the calculation
        auto const N = prefix_sum.size() - 1;

        for(int i = 0; i < N; ++i) {
            auto ref_itr = std::next(ps_start, i);
            auto sum = target + *ref_itr;
            auto itr = std::lower_bound(ps_start, ps_end, sum);
            if(itr != ps_end) {
                int subarray_size = std::distance(ref_itr, itr);
                min_subarray_size = std::min(min_subarray_size, subarray_size);
            }
        }

        if (equal_to(min_subarray_size,
                     std::numeric_limits<int>::max())) {
            return 0;
        }

        return  min_subarray_size;
    }
}
