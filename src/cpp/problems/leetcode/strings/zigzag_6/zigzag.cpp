#include "zigzag.hpp"

#include <sstream>
#include <vector>

namespace algo::problems::leetcode::strings::zigzag_6 {

    std::string ZigZag::convert(std::string s, std::int32_t numRows) {
        if (numRows >= s.length() or numRows == 1) {
            return s;
        }

        std::vector<std::string> zigzag(numRows);
        int row {};
        bool populateVertically = true;
        for (auto ch: s) {
            if (populateVertically) {
                if (row < numRows) {
                    zigzag[row] += ch;
                    ++row;
                    continue;
                }
            }

            if (row == numRows) {
                populateVertically = false;
                --row; // bring back row in range
            }

            zigzag[--row] += ch;
            if (row == 0) {
                ++row; // first row has already been populted .. so skip it
                populateVertically = true;
            }
        }

        std::stringstream result;
        for (auto &ss : zigzag) {
            result << ss;
        }
        return result.str();
    }
}