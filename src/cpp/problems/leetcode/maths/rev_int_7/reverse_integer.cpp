/**
 * Space Complexity: O(1)
 * Time Complexity : O(log(n)) => here log is of base 10
 */

#include "reverse_integer.hpp"

#include <cstdint>
#include <limits>

namespace {
    constexpr std::int32_t INT_MAX_CELING = std::numeric_limits<std::int32_t>::max() / 10;
    constexpr std::int32_t MAX_INT_TOLERANCE = std::numeric_limits<std::int32_t>::max() - INT_MAX_CELING;
    constexpr std::int32_t INT_MIN_CEILING = std::numeric_limits<std::int32_t>::min() / 10;
    constexpr std::int32_t MIN_INT_TOLERANCE = std::numeric_limits<std::int32_t>::min() - INT_MIN_CEILING;
}

namespace algo::problems::leetcode::maths::rev_int {

    int ReverseInteger::reverse(int x) {
        std::int32_t rev {};

        while (x != 0) {
            // check for overflows
            if (rev > INT_MAX_CELING or rev < INT_MIN_CEILING) {
                return 0;
            }

            auto pop = x % 10;
            if (rev == INT_MAX_CELING and pop > MAX_INT_TOLERANCE) {
                return 0;
            }
            if (rev == INT_MIN_CEILING and pop < MIN_INT_TOLERANCE) {
                return 0;
            }

            x /= 10;
            rev = 10 * rev + pop;
        }

        return rev;
    }

}