#include "palindromic_substrings.hpp"

#include <utils/dstypedefs.hpp>

/**
 * Space Complexity: O(N^2)
 * Time Complexity: O(N^2)
 */

using namespace algo::cpp::ds::utils;

namespace algo::interview::medium::string::palindromic_substring {

    bool isPalindrome(std::string const& s, int low, int high, Matrix<int>& dp) {
        int left{low}, right{high};

        while (left < right) {
            if (dp[left][right] != -1) {
                return dp[left][right] != 0;
            }

            if (s[left] != s[right]) {
                dp[left][right] = 0;
                return false;
            }
            ++left;
            --right;
        }

        dp[low][high] = 1;
        return true;
    }

    int PalindromicSubstrings::countSubstrings(const std::string &s) {
        using namespace algo::cpp::ds::utils;
        Matrix<int> dp { s.size(), std::vector<int>(s.size(), -1) };
        int count{0};

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (isPalindrome(s, i, j, dp)) {
                    ++count;
                }
            }
        }

        return count;
    }
}