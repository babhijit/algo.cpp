#include "count_and_say.hpp"

#include <sstream>
#include <utility>
#include <vector>

/**
 * Time Complexity: O(2^N)
 * Space Complexity: O(2^N)
 */

namespace algo::interview::medium::string::count_n_say {

    using CharCounter = std::pair<char, int>;

    std::vector<CharCounter> getCharCounter(std::string const& s) {
        std::vector<CharCounter> charCounter;

        std::size_t i = 1;
        char lastChar = s[0];
        char cnt = 1;
        while (i < s.size()) {
            char currentChar = s[i];
            if (currentChar == lastChar) {
                ++cnt;
            } else {
                charCounter.emplace_back(lastChar, cnt);
                cnt = 1;
                lastChar = currentChar;
            }
            ++i;
        }

        charCounter.emplace_back(lastChar, cnt);

        return charCounter;
    }

    std::string CountAndSay::countAndSay(std::string const& s, int n) {
        if (n == 0) {
            return s;
        }

        auto counter = getCharCounter(s);

        std::ostringstream oss;
        for (auto [ch, cnt]: counter) {
            oss << cnt << ch;
        }

        return countAndSay(oss.str(), n - 1);
    }

    std::string CountAndSay::countAndSay(int n) {
        return countAndSay("1", n - 1);
    }
}