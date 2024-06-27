#pragma once

#include <functional>
#include <vector>

namespace algo::problems::leetcode::deque::longest_cont_subarr_absdiff_le_limit {

    class LongestContinousSubArray {
        using Predicate = std::function<bool(int, int)>;

    public:
        LongestContinousSubArray();

        int longestSubarrary(std::vector<int> &nums, int limit);

    private:
        Predicate lessThan_;
        Predicate greaterThan_;

    };

}
