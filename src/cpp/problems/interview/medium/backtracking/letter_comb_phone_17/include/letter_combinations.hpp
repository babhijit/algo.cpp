#pragma once

#include <string>
#include <vector>

namespace algo::problems::leetcode::interview::backtracing::letter_combinations {

    class LetterCombinations {
    public:
        std::vector<std::string> letterCombinations(std::string const &digits);

    private:
        void letterCombinations(std::string const& s,
                                std::string const &digits,
                                std::size_t index,
                                std::vector<std::string> &combinations);

        static inline std::vector<std::string> s_combinations{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    };
}
