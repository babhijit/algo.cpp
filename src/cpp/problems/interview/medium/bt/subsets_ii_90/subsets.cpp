#include "subsets.hpp"

#include <algorithm>
#include <vector>

/**
 * Time Complexity: O(N* 2^N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::bt::subsets_ii {

    class Impl {
    public:
        explicit Impl(std::vector<int> &nums_) : nums(nums_) {
            std::vector<int> currentSubset;

            bt(subsets, currentSubset, 0);
        }

        [[nodiscard]] Matrix<int> subsetsWithDup() const {
            return subsets;
        }

    private:
        void bt(std::vector<std::vector<int>>& subsets, std::vector<int> currentSubset, int index) {
            subsets.push_back(currentSubset);

            for (int i = index; i < nums.size(); ++i) {
                // if the current element is a duplicate then ignore
                if ((i != index) and (nums[i] == nums[i - 1])) {
                    continue;
                }

                currentSubset.push_back(nums[i]);
                bt(subsets, currentSubset, i + 1);
                currentSubset.pop_back();
            }
        }

    private:
        std::vector<int> &nums;
        std::vector<std::vector<int>> subsets;
    };

    Matrix<int> Subsets::subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        Impl impl(nums);
        return impl.subsetsWithDup();
    }

}