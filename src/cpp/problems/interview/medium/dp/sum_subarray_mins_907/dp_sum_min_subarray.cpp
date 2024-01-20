#include "dp_sum_min_subarray.hpp"

#include <numeric>
#include <stack>
#include <vector>

namespace algo::interview::medium::dp::sum_subarray_mins {

    constexpr auto MOD = 1'000'000'007;

    int DpSumOfSubarrayMins::sumSubarrayMins(std::vector<int> &arr) {
        std::vector<long> subArraySums(arr.size(), 0);
        std::stack<int> monotonicIncreasingStack;

        for (int i = 0; i < arr.size(); ++i) {
            // pop all elements from stack
            while (not monotonicIncreasingStack.empty() and (arr[i] < arr[monotonicIncreasingStack.top()])) {
                monotonicIncreasingStack.pop();
            }

            if (monotonicIncreasingStack.empty()) {
                subArraySums[i] = (i + 1) * arr[i];
            } else {
                auto prevSmaller = monotonicIncreasingStack.top();
                subArraySums[i] = subArraySums[prevSmaller] + (i - prevSmaller) * arr[i];
            }

            monotonicIncreasingStack.push(i);
        }

        long sumOfMins = std::transform_reduce(std::begin(subArraySums),
                                               std::end(subArraySums),
                                               0L,
                                               std::plus<>(),
                                               [](long x) { return x % MOD; }
        );
        return static_cast<int>(sumOfMins % MOD);
    }
}