#include "gen_parentheses.hpp"

/**
 * Time Complexity: O(2^N)
 * Space Complexity: O(2^N)
 */

namespace algo::problems::leetcode::interview::backtracing::gen_paren {

    void generateParenthesesImpl(int leftParenCount,
                                 int rightParenCount,
                                 int targetBraces,
                                 std::string parenStr,
                                 std::vector<std::string> &parentheses) {
        // terminating condition
        if (leftParenCount == targetBraces) {
            // close all open braces
            parentheses.push_back(parenStr + std::string(targetBraces - rightParenCount, ')'));
            return;
        }

        generateParenthesesImpl(leftParenCount + 1, rightParenCount, targetBraces, parenStr + "(", parentheses);

        if (rightParenCount < leftParenCount) {
            generateParenthesesImpl(leftParenCount, rightParenCount + 1, targetBraces, parenStr + ")", parentheses);
        }
    }

    std::vector<std::string> GenerateParenthesis::generateParentheses(int n) {
        std::vector < std::string > parentheses;

        generateParenthesesImpl(0, 0, n, "", parentheses);

        return {parentheses.begin(), parentheses.end()};
    }
}