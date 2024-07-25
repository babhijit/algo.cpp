#include "basic_calc.hpp"

#include <deque>
#include <numeric>
#include <stdexcept>
#include <unordered_map>

namespace algo::problems::leetcode::interview::stack::basic_calc2 {

    int calc(std::deque<int>& numbers, int n, char op) {
        if (op == '-') {
            return -n;
        }

        if (numbers.empty()) {
            return n;
        }

        auto t = numbers.back();
        numbers.pop_back();

        if (op == '*') {
            return t * n;
        }

        if (op == '/') {
            return t / n;
        }

        return t + n;
    }

    int BasicCalculator::calculate(const std::string &s) {
        std::deque<int> numbers;
        int cur{0};
        char op{'+'};

        for(auto ch: s) {
            if (std::isspace(ch)) {
                continue;
            }

            if (std::isdigit(ch)) {
                cur = 10*cur + (ch - '0');
                continue;
            }

            if (op != '+') {
                cur = calc(numbers, cur, op);
            }

            numbers.push_back(cur);

            cur = 0;
            op = ch;
        }

        auto r = calc(numbers, cur, op);
        return std::accumulate(numbers.begin(),numbers.end(), r, std::plus<>());
    }
}
