#include "spl_pos_in_bin_matrix.hpp"

#include <cassert>

namespace algo::problems::leetcode::array::spl_pos_in_bin_matrix_1582 {


    int SpecialPositionInBinaryMatrix::numSpecial(Matrix<int> &matrix) {

        assert(matrix.size() > 0 && "matrix must have at least one row");
        assert(matrix[0].size() > 0 && "matrix must have at least one column");

        auto const ROWS = matrix.size();
        auto const COLUMNS = matrix[0].size();

        int specialNumberCount{};
        std::vector<bool> skipRows(ROWS, false);

        for (auto r = 0; r < ROWS; ++r) {
            if (skipRows[r])    continue;

            auto index = getRowNonZeroElement(matrix[r]);
            if (index == -1)    continue;

            bool isStillSpecial = true;

            // check for non zero column elements
            for (int i = 0; i < ROWS; ++i) {
                if (i == r)     continue;
                if (matrix[i][index]) {
                    skipRows[i] = true;
                    isStillSpecial = false;
                }
            }

            if (not isStillSpecial)     continue;

            // check for non zero row elements
            for (int i = 0; i < COLUMNS; ++i) {
                if (i == index)     continue;

                if (matrix[r][i]) {
                    isStillSpecial = false;
                    break;
                }
            }

            if (isStillSpecial)     ++specialNumberCount;
        }

        return specialNumberCount;
    }

    int SpecialPositionInBinaryMatrix::getRowNonZeroElement(std::vector<int> &row) {
        for (auto it = 0; it < row.size(); ++it) {
            if (row[it] == 1) {
                return it;
            }
        }
        return -1;
    }

}