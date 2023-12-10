#include "largest_odd_num_in_str.hpp"


namespace algo::problems::leetcode::strings::largest_odd_num_in_str {

    std::string LargestOddNumberInString::largestOddNumber(std::string num) {
        for (auto it = num.rbegin(); it != num.rend(); ++it) {
            auto n = *it - '0';
            if (isOdd(n)) {
                auto d = std::distance(it, num.rend());
                return num.substr(0, d);
            }
        }

        return {};
    }
}
