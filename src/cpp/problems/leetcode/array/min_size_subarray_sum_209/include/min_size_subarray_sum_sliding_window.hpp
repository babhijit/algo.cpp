#ifndef ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_SLIDING_WINDOW_HPP
#define ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_SLIDING_WINDOW_HPP

#include <functional>
#include <vector>
#include "abstract_min_size_subarray_sum.hpp"


namespace algo::problems::leetcode::array::min_size_subarray_sum {

    class MinSizeSubarraySum_SlidingWindow : public AbstractMinSizeSubarraySum {
    public:
        int minSubArrayLen(int target, std::vector<int> &nums) override;
    };

}

#endif //ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_SLIDING_WINDOW_HPP
