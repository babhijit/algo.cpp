#include "sum_min_subarray.hpp"

#include <stack>

namespace algo::problems::leetcode::stack::sum_subarray_mins {

    constexpr auto MOD = 1'000'000'007;

    int SumOfSubarrayMins::sumSubarrayMins(std::vector<int> &arr) {
        long sumOfMins{};
        std::stack<int> indices;

        for (int i = 0; i <= arr.size(); ++i) {
            // here we are doing a strictly monotonically increasing stack of indices
            while (not indices.empty() and ((i == arr.size()) or (arr[indices.top()] >= arr[i]))) {
                auto mid = indices.top();
                indices.pop();
                auto leftBoundary = indices.empty() ? -1 : indices.top();
                auto rightBoundary = i;

                // as two very large integers can give really large values so we are rounding off to MOD
                long subArrayCount = (mid - leftBoundary) * (rightBoundary - mid) % MOD;
                sumOfMins += subArrayCount * arr[mid] % MOD;
                sumOfMins %= MOD;
            }

            indices.push(i);
        }

        return static_cast<int>(sumOfMins);
    }
}