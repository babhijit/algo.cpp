#include "subsets.hpp"

#include <set>
#include <vector>

/**
 * Time Complexity: O (2^N)
 * Space Complexity: O(2^N)
 */

namespace algo::interview::medium::bt::subsets_ii {

    class Impl {
    public:
        explicit Impl(std::vector<int> &nums_) : nums(nums_) {
            for(std::size_t i = 0; i < nums.size(); ++i) {
                bt({},  i);
            }
        }

        [[nodiscard]] Matrix<int> subsetsWithDup() const {
            Matrix<int> result;

            for (auto& subset: subsets) {
                result.emplace_back(subset.begin(), subset.end());
            }

            return result;
        }

    private:
        void bt(std::set<int> lastSubset, int index) {
            if (index == nums.size()) {
                subsets.insert(lastSubset);
                return;
            }

            bt(lastSubset, index + 1);
            lastSubset.insert(nums[index]);
            bt(lastSubset, index + 1);
        }

    private:
        std::vector<int> &nums;
        std::set<std::set<int>> subsets;
    };

    Matrix<int> Subsets::subsetsWithDup(std::vector<int> &nums) {
        Impl impl(nums);
        return impl.subsetsWithDup();
    }

}