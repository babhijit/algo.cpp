#include <numeric>
#include "equivalent_strings.hpp"

namespace algo::problems::leetcode::strings::equivalent_strings {

    bool EquivalentStrings::areStringsEquivalent(
            std::vector<std::string> word1,
            std::vector<std::string> word2) {

        if (getTotalCharCount(word1) != getTotalCharCount(word2)) {
            return false;
        }

        auto word1Itr = std::begin(word1);
        auto word2Itr = std::begin(word2);

        auto ch1Itr = std::begin(*word1Itr);
        auto ch2Itr = std::begin(*word2Itr);

        while (word1Itr != std::end(word1) && word2Itr != std::end(word2)) {

            if ((ch1Itr != std::end(*word1Itr)) && (ch2Itr != std::end(*word2Itr))) {
                if (*ch1Itr != *ch2Itr) {
                    return false;
                }
                ++ch1Itr;
                ++ch2Itr;
            }

            if (ch1Itr == std::end(*word1Itr)) {
                ++word1Itr;

                if (word1Itr != std::end(word1)) {
                    ch1Itr = std::begin(*word1Itr);
                }
            }
            if (ch2Itr == std::end(*word2Itr)) {
                ++word2Itr;

                if (word2Itr != std::end(word2)) {
                    ch2Itr = std::begin(*word2Itr);
                }
            }
        }

        // if both iterators are at the end, then the strings are equivalent
        return ((word1Itr == std::end(word1))
                && (word2Itr == std::end(word2))
        );
    }

    std::size_t EquivalentStrings::getTotalCharCount(std::vector<std::string> const &word) {
        return std::accumulate(std::begin(word), std::end(word), 0,
                               [](std::size_t acc, std::string const &s) -> std::size_t {
                                   return acc + s.size();
                               });
    }

} // namespace algo::problems::leetcode::strings::equivalent_strings
