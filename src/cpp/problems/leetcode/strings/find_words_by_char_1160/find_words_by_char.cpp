#include "find_words_by_char.hpp"

#include <cassert>
#include <algorithm>

namespace algo::problems::leetcode::strings::find_words_by_char {

    int FindWordsByChar::countCharacters(std::vector<std::string> words,
                                         std::string chars) {
        assert(not chars.empty() && "chars should not be empty");
        assert(not words.empty() && "words should not be empty");

        int charsUsed{};
        auto frequencies = getCharFrequencies(chars);

        for (auto &word: words) {
            if (contains(word, frequencies)) {
                charsUsed += word.size();
            }
        }

        return charsUsed;
    }

    bool FindWordsByChar::contains(std::string const &word,
                                   CharCounter const &charFrequencies) {
        CharCounter counter{};

        for (auto c: word) {
            if (++counter[c - 'a'] > charFrequencies[c - 'a']) {
                return false;
            }
        }

        return true;
    }

    FindWordsByChar::CharCounter FindWordsByChar::getCharFrequencies(const std::string &chars) {
        CharCounter frequencies{};
        for (auto c: chars) {
            frequencies[c - 'a']++;
        }
        return frequencies;
    }

} // namespace algo::problems::leetcode::strings::find_words_by_char
