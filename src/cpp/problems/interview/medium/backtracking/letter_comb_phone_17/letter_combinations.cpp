#include "letter_combinations.hpp"

/**
 * Time Complexity = O( N * 4^N )
 * Space Complexity = O(N)
 *
 */

namespace algo::problems::leetcode::interview::backtracing::letter_combinations {

    std::vector<std::string> LetterCombinations::letterCombinations(std::string const &digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector < std::string > combinations;

        letterCombinations("", digits, 0, combinations);

        return combinations;
    }

    void LetterCombinations::letterCombinations(std::string const &s,
                                                std::string const &digits,
                                                std::size_t index,
                                                std::vector<std::string> &combinations) {
        if (index == digits.size()) {
            combinations.push_back(s);
            return;
        }

        auto digit = digits[index] - '2';
        auto &combination = s_combinations[digit];
        for (auto letter: combination) {
            letterCombinations(s + letter, digits, index + 1, combinations);
        }
    }
}