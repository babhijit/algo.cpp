#include "transpose_matrix.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::transpose_matrix {
    using IntMarix = std::vector<std::vector<int>>;

    std::vector<std::vector<int>> TransportMatrix::transpose(std::vector<std::vector<int>> &matrix) {
        if (matrix.empty()) {
            return {};
        }

        auto rows = matrix.size();
        auto cols = matrix[0].size();

        IntMarix result(cols, std::vector<int>(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
}