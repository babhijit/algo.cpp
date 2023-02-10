#include "remove_k_digits.hpp"

#include <algorithm>
#include <memory>
#include <stack>
#include <string>

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

        while(k) {
            monotonic.pop();
            --k;
        }

        std::string result;
        while(!monotonic.empty()) {
            result.insert(result.begin(), monotonic.top());
            monotonic.pop();
        }

        auto pos = result.find_first_not_of('0');
        if (pos == result.npos)
            return "0";
        return result.substr(pos);
    }

}
