#include "remove_k_digits.hpp"

#include <algorithm>
#include <memory>
#include <stack>
#include <string>
#include <sstream>

namespace algo::problems::leetcode::stack::remove_k_digits {

    std::string RemoveKDigits::removeKdigits(std::string num, int k) {
        auto const N = num.size();

        if (N == k)
            return "0";

        if (!k) {
            return num;
        }

        std::stack<char> monotonic;
        monotonic.push(num[0]);

        for (int i = 1; i < N; ++i) {
            auto digit = num[i];
            while (!monotonic.empty() && k && (monotonic.top() > digit)) {
                monotonic.pop();
                --k;
            }

            monotonic.push(digit);
        }

        while (k) {
            monotonic.pop();
            --k;
        }

        std::stack<char> digits;
        while (!monotonic.empty()) {
            digits.push(monotonic.top());
            monotonic.pop();
        }

        std::ostringstream oss;
        bool skip_leading_zeros = true;
        while (!digits.empty()) {
            auto digit = digits.top();
            digits.pop();
            if (skip_leading_zeros) {
                if (digit != '0') {
                    skip_leading_zeros = false;
                } else {
                    continue;
                }
            }
            oss << digit;
        }

        auto result = oss.str();
        return result.empty() ? "0" : result;
    }

}
