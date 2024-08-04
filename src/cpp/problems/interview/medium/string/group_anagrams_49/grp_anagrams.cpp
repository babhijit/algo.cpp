#include "grp_anagrams.hpp"

#include <algorithm>
#include <unordered_map>
#include <vector>

/**
 * Time Complexity: O(N*M)
 * Space Complexity: O(N*M)
 */

namespace algo::interview::medium::string::group_anagrams {

    using Token = std::unordered_map<char, int>;
    struct TokenHash {
        std::size_t operator()(Token const& token) const {
            std::size_t hash{0};
            for (const auto&[key, value]: token) {
                hash ^= std::hash<char>{}(key) ^ std::hash<int>{}(value);
            }
            return hash;
        }
    };

    Token getToken(std::string const& str) {
        Token tokens;
        for (auto ch: str) {
            auto& cnt = tokens[ch];
            ++cnt;
        }
        return tokens;
    }

    Matrix<std::string> GroupAnagram::groupAnagrams(std::vector<std::string> &strings) {
        std::unordered_map<Token, std::vector<std::string>, TokenHash> anagrams;
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
