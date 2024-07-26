#include "sub_array_sums.hpp"

#include <unordered_map>

namespace algo::interview::medium::array::sub_array_sum {

    /**
     * Time Complexity : O(n)
     * Space Complexity: O(n)
     */

    int SubArraySum::subarraySum(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        int sum{0};
        int numOfSubarrays{0};
        for (auto &num: nums) {
            sum += num;
            auto remainder = sum - k;
            if (prefixSum.contains(remainder)) {
                numOfSubarrays += prefixSum[remainder];
            }

            auto &count = prefixSum[sum];
            ++count;
        }

        return numOfSubarrays;
    }

}