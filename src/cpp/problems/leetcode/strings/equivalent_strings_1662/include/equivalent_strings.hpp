#ifndef ALGO_CPP_EQUIVALENT_STRINGS_HPP
#define ALGO_CPP_EQUIVALENT_STRINGS_HPP

#include <string>
#include <vector>

namespace algo::problems::leetcode::strings::equivalent_strings {

    class EquivalentStrings {
    public:
        bool areStringsEquivalent(std::vector<std::string> word1, std::vector<std::string> word2);

    private:
        static std::size_t getTotalCharCount(std::vector<std::string> const& word);
    };

}

#endif //ALGO_CPP_EQUIVALENT_STRINGS_HPP
