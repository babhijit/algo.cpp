#include "three_sum.hpp"

#include <algorithm>
#include <set>
#include <stdexcept>

/**
 * Time Complexity: O( N^2 Log(N) )
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::array::three_sum {

    std::vector<std::vector<int>> ThreeSum::threeSum(std::vector<int> &nums) {
        if (nums.size() < 3) {
            throw std::logic_error("nums must contain at least 3 elements");
        }

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;
        auto iEnd = std::prev(std::end(nums), 2);
        auto jEnd = std::prev(std::end(nums));
        for (auto iItr = std::begin(nums); iItr != iEnd; iItr = std::upper_bound(std::next(iItr), iEnd, *iItr)) {
            for (auto jItr = std::next(iItr); jItr != jEnd; jItr = std::upper_bound(std::next(jItr), jEnd, *jItr)) {
                auto twoSum = *iItr + *jItr;
                if (std::binary_search(std::next(jItr), std::end(nums), -twoSum)) {
                    results.push_back({*iItr, *jItr, -twoSum});
                }
            }
        }

        return results;
    }
}