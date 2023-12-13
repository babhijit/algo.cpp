#pragma once

#include <vector>

namespace algo::problems::leetcode::array::spl_pos_in_bin_matrix_1582 {

    class SpecialPositionInBinaryMatrix {

        template<typename T>
        using Matrix = std::vector<std::vector<T>>;

    public:
        int numSpecial(Matrix<int>& matrix);

        int getRowNonZeroElement(std::vector<int> &row);
    };

}