#include "grp_anagrams.hpp"

#include <algorithm>
#include <map>
#include <vector>

/**
 * Time Complexity: O(N*M)
 * Space Complexity: O(N*M)
 */

namespace algo::interview::medium::string::group_anagrams {

    using Token = std::map<char, int>;

    Token getToken(std::string const& str) {
        Token tokens;
        for (auto ch: str) {
            auto& cnt = tokens[ch];
            ++cnt;
        }
        return tokens;
    }

    Matrix<std::string> GroupAnagram::groupAnagrams(std::vector<std::string> &strings) {
        std::map<Token, std::vector<std::string>> anagrams;
        for (auto const& str: strings) {
            auto token = getToken(str);
            auto& words = anagrams[token];
            words.push_back(str);
        }

        Matrix<std::string> anagramGroup;
        for (auto &[_, words]: anagrams) {
            std::vector<std::string> anagramList;
            std::for_each(words.begin(), words.end(), [&anagramList](auto const& str) {
                anagramList.push_back(str);
            });
            anagramGroup.push_back(anagramList);
        }
        return anagramGroup;
    }
}
