#include "palindromic_substrings.hpp"

#include <utils/dstypedefs.hpp>

/**
 * Space Complexity: O(1)
 * Time Complexity: O(N^3)
 */

namespace algo::interview::medium::string::palindromic_substring {

    bool isPalindrome(std::string const& s, int low, int high) {
        int left{low}, right{high};

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    int PalindromicSubstrings::countSubstrings(const std::string &s) {
        using namespace algo::cpp::ds::utils;
        Matrix<int> dp;
        int count{0};

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (isPalindrome(s, i, j)) {
                    ++count;
                }
            }
        }

        return count;
    }
}