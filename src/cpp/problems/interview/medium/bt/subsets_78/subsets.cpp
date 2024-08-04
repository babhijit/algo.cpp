#include "subsets.hpp"

/**
 * Time Complexity: O (2^N)
 * Space Complexity: O(2^N)
 */

namespace algo::interview::medium::bt::subsets {

    void backtrack(std::vector<int>& nums, std::vector<int> workingSet, int index, Matrix<int>& result) {
        if (index == nums.size()) {
            result.push_back(workingSet);
            return;
        }

        backtrack(nums, workingSet, index+1, result);

        workingSet.push_back(nums[index]);
        backtrack(nums, workingSet, index+1, result);
    }


    Matrix<int> Subsets::subsets(std::vector<int> &nums) {
        Matrix<int> result;

        backtrack(nums, {}, 0, result);

        return result;
    }

}