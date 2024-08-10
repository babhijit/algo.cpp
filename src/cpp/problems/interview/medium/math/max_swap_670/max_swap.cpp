#include "max_swap.hpp"

#include <vector>
#include <utility>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::math::max_swap {

    std::vector<int> toVector(int num) {
        std::vector<int> number;
        while (num > 0) {
            auto digit = num % 10;
            number.push_back(digit);
            num /= 10;
        }

        std::reverse(number.begin(), number.end());
        return number;
    }

    int toNumber(std::vector<int> &digits) {
        int order = 1;
        int number = 0;
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            number += order * digits[i];
            order *= 10;
        }

        return number;
    }

    void swapMaximum(std::vector<int> &digits) {
        std::vector<int> digitPositions(10, -1);
        for (int i = 0; i < digits.size(); ++i) {
            auto const& digit = digits[i];
            digitPositions[digit] = i;
        }

        for (int i = 0; i < digits.size(); ++i) {
            for (int pos = 9; pos >= 0; --pos) {
                auto &digitPosition = digitPositions[pos];
                if (digitPosition == -1) {
                    continue;
                }

                // Conditions for swap:
                //  1. The current digit must be smaller than the bigger value
                //  2. The position of the higher value must be AFTER the current smaller value
                if ((digitPosition > i) and (digits[digitPosition] > digits[i])) {
                    std::swap(digits[digitPosition], digits[i]);
                    return;
                }
            }
        }
    }

    int MaxSwap::maximumSwap(int num) {
        if (num == 0) {
            return num;
        }

        auto number = toVector(num);

        swapMaximum(number);

        return toNumber(number);

    }
}