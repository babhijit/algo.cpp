#include "buy_2_choc.hpp"

#include <algorithm>

namespace algo::problems::leetcode::array::buy_2_choc_2706 {

    int Buy2Chocolates::buyChoco(std::vector<int> &prices, int money) {
        std::sort(std::begin(prices), std::end(prices));

        auto cost = prices[0] + prices[1];
        return money < cost ? money : (money - cost);
    }
}