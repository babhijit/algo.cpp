#ifndef ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_HPP
#define ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_HPP

#include <vector>

#include "abstract_min_size_subarray_sum.hpp"


namespace algo::problems::leetcode::array::min_size_subarray_sum {

    class MinSizeSubarraySum {
        AbstractMinSizeSubarraySum *impl;

    public:
        explicit MinSizeSubarraySum(AbstractMinSizeSubarraySum *impl_) : impl(impl_) {}

        int minSubArrayLen(int target, std::vector<int> &nums) {
            return impl->minSubArrayLen(target, nums);
        }

    };

} // min_size_subarray_sum

#endif //ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_HPP
