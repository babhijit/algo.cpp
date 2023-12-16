#include "valid_anagram.hpp"

#include <array>


namespace algo::problems::leetcode::strings::valid_anagram_242 {

    bool ValidAnagram::isAnagram(std::string const& s, std::string const& t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::array<int, CHARS> freqS = getCharFreq(s);
        std::array<int, CHARS> freqT= getCharFreq(t);

        return areFreqEqual(freqS, freqT);

    }

    std::array<int, ValidAnagram::CHARS> ValidAnagram::getCharFreq(const std::string &str) {
        std::array<int, CHARS> freq{};

        for(auto ch: str) {
            auto ascii = ch - 'a';
            ++freq[ascii];
        }

        return freq;
    }

    bool ValidAnagram::areFreqEqual(std::array<int, CHARS> a, std::array<int, CHARS> b) const noexcept {
        for (int i = 0; i < CHARS; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

}