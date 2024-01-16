#include "three_sum.hpp"

#include <algorithm>
#include <set>
#include <stdexcept>

namespace algo::interview::medium::array::three_sum {

    std::vector<std::vector<int>> ThreeSum::threeSum(std::vector<int> &nums) {
        std::set<std::vector<int>> results;

        if (nums.size() < 3) {
            throw std::logic_error("nums must contain at least 3 elements");
        }

        std::sort(nums.begin(), nums.end());
        auto i_last = std::prev(std::end(nums), 2);
        auto j_last = std::prev(std::end(nums));
        for (auto i_itr = std::begin(nums); i_itr != i_last; ++i_itr) {
            std::vector<int>::iterator  itr;
            auto j_itr = std::next(i_itr);
            while (j_itr != j_last) {
                auto twoSum = *i_itr + *j_itr;
                if (std::binary_search(std::next(j_itr), std::end(nums), -twoSum)) {
                    results.emplace(std::vector({*i_itr, *j_itr, -twoSum}));
                }

                // we have already taken duplicates in three sum, now we need to skip them
                itr = std::lower_bound(std::next(j_itr), j_last, *j_itr);
                if (*itr == *j_itr) {
                    j_itr = itr;
                }

                if (j_itr != j_last) {
                    ++j_itr;
                }
            }

            // skip through the duplicates
            itr = std::lower_bound(std::next(i_itr), i_last, *i_itr);
            if ((itr != i_last) and (*itr == *i_itr)) {
                i_itr = itr;
            }
        }

        if (results.empty()) {
            return {{}};
        }
        return {std::begin(results), std::end(results)};
    }
}