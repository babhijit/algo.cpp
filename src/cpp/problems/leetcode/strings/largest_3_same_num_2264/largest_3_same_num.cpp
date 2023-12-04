#include "largest_3_same_num.hpp"

#include <optional>


namespace algo::problems::leetcode::strings::largest_3_same_num {

    std::string Largest3NumberInString::largestGoodInteger(std::string num) {
        const std::size_t N = num.size();
        if (N < 3) {
            return {};
        }

        std::optional<char> goodDigit = std::nullopt;

        int i {};
        while (i < (N - 2)) {
            if (num[i] == num[i+1]) {
                if (num[i] == num[i+2]) {
                    if (not goodDigit or (num[i] > *goodDigit)) {
                        goodDigit = num[i];
                    }
                    i += 3;
                } else {
                    i += 2;
                }
            } else {
                ++i;
            }
        }

        if (goodDigit) {
            return std::string(3, *goodDigit);
        }

        return {};
    }
}