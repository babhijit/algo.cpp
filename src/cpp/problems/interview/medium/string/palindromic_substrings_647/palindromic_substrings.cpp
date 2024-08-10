#include "palindromic_substrings.hpp"

/**
 * Time Complexity: O(N^2)
 *      N * (2N - 1) Substring checks for palindromes
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::string::palindromic_substring {

    int palindromesAroundCentre(std::string const& str, int low, int high) {
        int palindromes {0};

        while((low >= 0) and (high < str.size())) {
            if (str[low] != str[high]) {
                break;
            }
            ++palindromes;
            --low;
            ++high;
        }

        return palindromes;
    }

    int PalindromicSubstrings::countSubstrings(const std::string &s) {
        int palindromes {0};

        for (int i = 0; i < s.size(); ++i) {
            palindromes += palindromesAroundCentre(s, i, i);
            palindromes += palindromesAroundCentre(s, i, i + 1);
        }

        return palindromes;
    }
}