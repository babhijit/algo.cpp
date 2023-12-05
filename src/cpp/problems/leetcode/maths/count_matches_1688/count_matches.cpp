#include "count_matches.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::maths::count_matches {

    int CountMatches::numberOfMatches(int n) {
        if (n < 1 || n > 200) {
            throw std::invalid_argument("n must be in range [1, 200]");
        }

        int matches {};
        while (n > 1) {
            if (isEven(n)) {
                matches += n / 2;
                n /= 2;
            } else {
                matches += (n - 1) / 2;
                n = ((n - 1) / 2) + 1;
            }
        }

        return matches;
    }
}