#ifndef ALGO_CPP_FIND_WORDS_BY_CHAR_HPP
#define ALGO_CPP_FIND_WORDS_BY_CHAR_HPP

#include <array>
#include <string>
#include <vector>

namespace algo::problems::leetcode::strings::find_words_by_char {

    class FindWordsByChar {
        using CharCounter = std::array<int, 26>;
    public:
        int countCharacters(std::vector<std::string> words, std::string chars);

    private:
        static bool contains(std::string const& word, CharCounter const& charFrequencies);
        static CharCounter getCharFrequencies(std::string const& chars);
    };

}

#endif //ALGO_CPP_FIND_WORDS_BY_CHAR_HPP
