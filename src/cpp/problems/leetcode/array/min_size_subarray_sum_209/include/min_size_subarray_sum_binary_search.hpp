#ifndef ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_BINARY_SEARCH_HPP
#define ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_BINARY_SEARCH_HPP

#include <functional>
#include <vector>
#include "abstract_min_size_subarray_sum.hpp"

namespace algo::problems::leetcode::array::min_size_subarray_sum {

    class MinSizeSubarraySum_BinarySearch : public AbstractMinSizeSubarraySum {

    public:
        int minSubArrayLen(int target, std::vector<int> &nums) override;

    private:
        static std::vector<int> get_prefix_sum(std::vector<int> const &nums);

    };

}


#endif //ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_BINARY_SEARCH_HPP
