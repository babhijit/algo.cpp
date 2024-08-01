#include "contiguous_array.hpp"

#include <unordered_map>

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

namespace algo::interview::array::contiguous_array {
    int ContiguousArray::findMaxLength(std::vector<int> &nums) {
        std::unordered_map<int, int> sumTillIndex;

        int maxSubarrayLength{0};
        int sum{0};
        for (int i = 0; i < nums.size(); ++i ) {
            sum += (nums[i] == 0) ? -1 : +1;

            if (sum == 0) {
                auto length = i + 1; // compensating for 0-based index
                maxSubarrayLength = std::max(maxSubarrayLength, length);
                continue;
            }

            auto it = sumTillIndex.find(sum);
            if (it != sumTillIndex.end()) {
                auto startingIndex = it->second;
                auto length = i - startingIndex;
                maxSubarrayLength = std::max(maxSubarrayLength, length);
            } else {
                sumTillIndex[sum] = i;
            }
        }

        return maxSubarrayLength;
    }
}