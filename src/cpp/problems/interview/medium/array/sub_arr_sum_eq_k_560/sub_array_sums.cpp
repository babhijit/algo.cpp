#include "sub_array_sums.hpp"

namespace algo::interview::medium::array::sub_array_sum {

    int SubArraySum::subarraySum(std::vector<int> &nums, int k) {

        std::vector<int> preSum(nums.size(), 0);

        preSum[0] = nums[0];
        for(auto i = 1; i < nums.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i];
        }

        int numOfSubarray{0};
        for (int i = 0; i < preSum.size(); ++i) {
            if (preSum[i] == k) {
                ++numOfSubarray;
            }
            for (int j = i + 1; j < preSum.size(); ++j) {
                if (preSum[j] - preSum[i] == k) {
                    ++numOfSubarray;
                }
            }
        }

        return numOfSubarray;
    }

}