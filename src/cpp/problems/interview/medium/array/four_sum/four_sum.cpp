#include "four_sum.hpp"

#include <algorithm>
#include <set>

/**
 * Time Complexity: O(n^3)
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::array::four_sum {

    Matrix<int> FourSum::fourSum(std::vector<int> &nums, int target) {
        std::sort(std::begin(nums), std::end(nums));

        std::set<std::vector<int>> results;

        for (auto i = 0; i < nums.size() - 3; ++i) {
            for (auto j = i + 1; j < nums.size() - 2; ++j) {
                std::int64_t sum = nums[i] + nums[j];
                std::int64_t rem = target - sum;
                auto twoSums = getAllTwoSums(nums, j + 1, nums.size() - 1, rem);
                for (auto &twoSum: twoSums) {
                    results.insert({nums[i], nums[j], twoSum.first, twoSum.second});
                }
            }
        }

        return {results.begin(), results.end()};
    }

    std::vector<std::pair<int, int>> FourSum::getAllTwoSums(std::vector<int> &nums,
                                                            std::size_t start, std::size_t end,
                                                            std::int64_t target) {

        std::vector<std::pair<int, int>> result;

        while (start < end) {
            std::int64_t sum = nums[start] + nums[end];

            if (sum < target) {
                ++start;
            } else if (sum > target) {
                --end;
            } else {
                result.emplace_back(nums[start],  nums[end]);
                // look for other solutions
                ++start;
                --end;
            }
        }

        return result;
    }
}