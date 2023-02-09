#include "reverse_integer.hpp"


#include <limits>

namespace algo::problems::leetcode::reverse_integer {

    static constexpr int REVERSE_INT_MAX_CEILING = std::numeric_limits<int>::max() / 10;
    static constexpr int REV_INT_MAX_TOLERANCE = std::numeric_limits<int>::max() - REVERSE_INT_MAX_CEILING;
    static constexpr int REVERSE_INT_MIN_FLOOR = std::numeric_limits<int>::min() / 10;
    static constexpr int REV_INT_MIN_TOLERANCE = std::numeric_limits<int>::min() - REVERSE_INT_MIN_FLOOR;
    int ReverseInteger::reverse(int x) {
        int rev = 0;

        while (x) {
            int pop = x % 10;
            x /= 10;

            // positive overflow check
            // edge case: multiplying rev by 10 naturally overflows
            if (rev > REV_INT_MAX_TOLERANCE)
                return 0;
            // edge case: adding >= 7 to rev means rev will have value greater than INT_MAX
            if ((rev == REV_INT_MAX_TOLERANCE) && (pop > REV_INT_MAX_TOLERANCE))
                return 0;

            // negative overflow check
            // edge case: multiplying rev by 10 naturally overflows on the min side
            if (rev < REVERSE_INT_MIN_FLOOR) {
                return 0;
            }
            // edge case: adding <= -8 to rev means rev will have value greater than INT_MIN
            if ((rev == REVERSE_INT_MIN_FLOOR) && (pop < REV_INT_MIN_TOLERANCE))
                return 0;

            rev = 10 * rev + pop;
        }

        return rev;
    }
}