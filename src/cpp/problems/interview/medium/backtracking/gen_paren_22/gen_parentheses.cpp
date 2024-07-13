#include "gen_parentheses.hpp"


/**
 * Time Complexity: O(2^N)
 * Space Complexity: O(2^N)
 */

namespace algo::problems::leetcode::interview::backtracing::gen_paren {

    void generateParenthesesImpl(int leftParenCount,
                                 int rightParenCount,
                                 int targetBraces,
                                 std::string& parenStr,
                                 std::vector<std::string> &parentheses) {
        // terminating condition
        if (leftParenCount == targetBraces) {
            // close all open braces
            parentheses.push_back(parenStr + std::string(targetBraces - rightParenCount, ')'));
            return;
        }

        parenStr.push_back('(');
        generateParenthesesImpl(leftParenCount + 1, rightParenCount, targetBraces, parenStr, parentheses);
        parenStr.pop_back();

        if (rightParenCount < leftParenCount) {
            parenStr.push_back(')');
            generateParenthesesImpl(leftParenCount, rightParenCount + 1, targetBraces, parenStr, parentheses);
            parenStr.pop_back();
        }
    }

    std::vector<std::string> GenerateParenthesis::generateParentheses(int n) {
        std::vector < std::string > parentheses;

        std::string param;
        generateParenthesesImpl(0, 0, n, param, parentheses);

        return {parentheses.begin(), parentheses.end()};
    }
}