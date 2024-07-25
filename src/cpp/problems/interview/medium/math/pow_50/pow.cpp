#include "pow.hpp"

#include <cmath>
#include <limits>

/**
 * Time Complexity: O(log n)
 * Space Complexity: O( log n )
 */

namespace algo::problems::leetcode::interview::math::pow {

    double exp(double x, long n) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 1.0 / exp(x, -n);
        }

        if (std::fabs(x - 0) < std::numeric_limits<double>::epsilon()) {
            return 0;
        }

        if (std::fabs(x - 1) < std::numeric_limits<double>::epsilon()) {
            return 1;
        }

        if (n % 2 == 0) {
            return exp(x * x, n / 2);
        } else {
            return x * exp(x , n - 1);
        }
    }

    double PoW::myPow(double x, int n) {
        return exp(x, n);
    }
}