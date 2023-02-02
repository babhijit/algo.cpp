#include "longest_consecutive_sequence.hpp"

#include <stdexcept>
#include <unordered_set>

namespace algo::problems::leetcode::array::longest_consecutive_seq {

    int LongestConsecutiveSequence::longestConsecutive(std::vector<int> &nums) {
        std::unordered_set<int> numbers(std::begin(nums), std::end(nums));

        int longest_streak = 0;
        for (auto current_number : numbers) {
            // check if the number is already part of an existing sequence
            if(numbers.contains(current_number - 1))
                continue;


            auto current_streak = 1;

            while(numbers.contains(++current_number)) {
                ++current_streak;
            }

            longest_streak = std::max(longest_streak, current_streak);
        }

        return longest_streak;
    }

} // longest_consecutive_seq