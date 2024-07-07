#include "str_to_int.hpp"

#include <algorithm>
#include <cctype>
#include <limits>

/**
 * Space Complexity : O(1)
 * Time Complexity: O(N)
 */

namespace {

    constexpr std::int32_t MAX_INT_CEILING = std::numeric_limits<std::int32_t>::max() / 10;
    constexpr std::int32_t LAST_DIGIT_TOLERANCE = std::numeric_limits<std::int32_t>::max() % 10;

    std::string trimLeading(std::string const &str) {
        int pos{};
        for (auto &ch: str) {
            if (ch == ' ') {
                ++pos;
            } else {
                break;
            }
        }

        return str.substr(pos);
    }

    std::string extractNumber(std::string const &str) {
        auto it = std::find_if(str.begin(), str.end(),
                               [](auto &ch) { return not std::isdigit(ch); });
        return {str.begin(), it};
    }

    std::int32_t toDigit(char ch) {
        return ch - '0';
    }

    std::int32_t toInteger(std::string const &str, std::int32_t sign) {
        std::int32_t number{};

        for (auto ch: str) {
            auto digit = toDigit(ch);

            if ((number > MAX_INT_CEILING) or
                ((number == MAX_INT_CEILING) and (digit > LAST_DIGIT_TOLERANCE))) {
                if (sign == 1) {
                    return std::numeric_limits<std::int32_t>::max();
                } else {
                    return std::numeric_limits<std::int32_t>::min();
                }
            }

            number = 10 * number + digit;
        }


        return sign * number;
    }
}

namespace algo::problems::leetcode::strings::to_integer {

    std::int32_t StrToInt::myAtoi(std::string s) {
        if (s.empty()) {
            return 0;
        }

        auto str = trimLeading(s);

        std::int32_t sign = 1;
        if (str[0] == '-') {
            sign = -1;
            str = str.substr(1);
        } else if (str[0] == '+') {
            str = str.substr(1);
        }

        str = extractNumber(str);
        return toInteger(str, sign);
    }
}