#include "next_permutation.hpp"

#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace algo::problems::leetcode::array::next_permutation {

    void NextPermutation::nextPermutation(std::vector<int> &nums) {
        if (nums.empty()) return;

        auto start = nums.begin();
        auto end = nums.end();

        auto greatest = getGreatestFromEnd(nums);

        // edge case: rollback to original if we are already at the highest lexicographical number
        if (greatest != start) {
            auto prevSmallest = std::prev(greatest);
            auto nextGreater = getNextGreater(greatest, end, *prevSmallest);
            std::iter_swap(prevSmallest, nextGreater);
        }
        std::reverse(greatest, end);
    }

    NextPermutation::IntVecItr NextPermutation::getGreatestFromEnd(std::vector<int> &nums) {
        auto itr = nums.end();
        while (--itr != nums.begin()) {
            if (less(*std::prev(itr), *itr))
                break;
        }
        return itr;
    }

    NextPermutation::IntVecItr NextPermutation::getNextGreater(IntVecItr first,
                                                               IntVecItr last,
                                                               int value) {
        auto upperBound = last;
        while(first != last) {
            auto distance = std::distance(first, last);
            auto half = distance >> 1;
            auto mid = std::next(first, half);

            if(less(value, *mid)) {
                upperBound = mid;
                first = std::next(mid);
            } else {
                last = mid;
            }
        }
        return upperBound;
    }

} //algo::problems::leetcode::array::next_permutation