#include "search_in_rotated_array.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::search_in_rotated_array {

    bool SearchInRotatedArray::search(std::vector<int> &nums, int target) {
        // edge case: vector is empty
        if (nums.empty())   return false;

        auto start = nums.begin();
        auto end = nums.end();
        while(start != end) {
            auto length = std::distance(start, end);
            auto half = length >> 1;
            auto mid = std::next(start, half);

            // found match
            if(equal_to(target, *mid))
                return true;

            if (!can_use_binary_search(start, mid)) {
                ++start;
                continue;
            }

            bool pivot_in_first = less_equal(*start, *mid);
            bool target_in_first = less_equal(*start, target);

            // pivot and target are present in distinct arrays
            if(pivot_in_first ^ target_in_first) {
                if(pivot_in_first) {
                    // pivot in the first and target in the second
                    start = ++mid;
                } else {
                    // target in the first, pivot in the second
                    end = mid;
                }
            } else {
                if (less(*mid, target)) {
                    start = ++mid;
                } else {
                    end = mid;
                }
            }
        }
        return false;
    }

    bool SearchInRotatedArray::can_use_binary_search(std::vector<int>::iterator start,
                                                     std::vector<int>::iterator mid) {
        return !equal_to(*start, *mid);
    }

}