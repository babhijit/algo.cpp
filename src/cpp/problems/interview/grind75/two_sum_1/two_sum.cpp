#include "two_sum.hpp"

#include <unordered_map>

/**
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */

namespace algo::interview::grind75::two_sum {

    std::vector<int> TwoSum::twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> indices;
        for(auto i = 0; i < nums.size(); ++i) {
            indices[nums[i]] = i;
        }

        for (auto i = 0; i < nums.size(); ++i) {
            auto a = nums[i];
            auto b = target - a;
            auto it = indices.find(b);

            if ((it != indices.end()) and (i != indices[b])) {
                return {i, indices[b]};
            }
        }

        return {};
    }
}