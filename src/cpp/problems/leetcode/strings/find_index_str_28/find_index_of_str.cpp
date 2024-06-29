#include "find_index_of_str.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::strings::find_index_of_str_28 {

    int FindIndexOfString::strStr(std::string const& haystack, std::string const& needle) {
        auto lps = getLps(needle);

        const auto textLength = haystack.size();
        const auto patternLength = needle.size();

        int i, j;
        for (i = 0, j = 0; (i < textLength) and (j < patternLength); ++i) {
            while(j >= 0 and haystack[i] != needle[j]) {
                j = lps[j];
            }
            ++j;
        }
        if (j == patternLength) {
            return i - patternLength; // return index of the string's start index
        }

        return -1;
    }

    std::vector<int> FindIndexOfString::getLps(const std::string &pattern) {
        std::vector<int> next(pattern.size(), 0);

        int j = -1;
        for (auto i = 0; i < pattern.size(); ++i) {
            if (i == 0) {
                next[i] = -1;
            } else if (pattern[i] != pattern[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
            while(j >= 0 and pattern[i] != pattern[j]) {
                j = next[j];
            }
            ++j;
        }

        return next;
    }

}