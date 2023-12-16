#pragma once

#include <string>
#include <array>

namespace algo::problems::leetcode::strings::valid_anagram_242 {

    class ValidAnagram {
        static constexpr int8_t CHARS = 26;

    public:
        bool isAnagram(std::string const& s, std::string const& t);

    private:
        std::array<int, CHARS> getCharFreq(const std::string &str);

        bool areFreqEqual(std::array<int, CHARS> a, std::array<int, CHARS> b) const noexcept;
    };

}