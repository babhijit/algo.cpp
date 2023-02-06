#ifndef ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_ABSTRACT_HPP
#define ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_ABSTRACT_HPP

#include <functional>
#include <vector>

namespace algo::problems::leetcode::array::min_size_subarray_sum {

    class AbstractMinSizeSubarraySum {
    protected:
        static constexpr auto equal_to = std::equal_to<>();
        static constexpr auto greater_equal = std::greater_equal<>();

    public:
        virtual int minSubArrayLen(int target, std::vector<int> &nums) = 0;
    };

} // min_size_subarray_sum

#endif //ALGO_CPP_MIN_SIZE_SUBARRAY_SUM_ABSTRACT_HPP
