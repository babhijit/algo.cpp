#include "rotate_image.hpp"

/**
 * Space Complexity: O(1)
 * Time Complexity: O(N * N)  .. Matrix[N][N]
 */

namespace algo::interview::medium::array::rotate_image {

    void rotateReflections_Diagonal_Vertical(Matrix<int> &matrix) {
        // reflect over diagonal
        for(int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reflect over vertical axis through the middel
        for(auto& row: matrix) {
            std::reverse(row.begin(), row.end());
        }
    }


    void RotateImage::rotate(Matrix<int> &matrix) {
        Matrix<int> origin = matrix;

        int left = 0;
        int right = static_cast<int>(matrix[0].size()) - 1;

        while (left < right) {
            auto top = left;
            auto bottom = right; // it's a square matrix so bottom and right have same values

            auto numberOfElements = right - left;
            for (int i = 0; i < numberOfElements; ++i) { // number of rotation is always numberOrElements - 1
                // save the top left
                auto topLeft = matrix[top][left + i];

                // move: [bottom->top][left]
                matrix[top][left + i] = matrix[bottom - i][left];

                // move: [bottom][right -> left]
                matrix[bottom - i][left] = matrix[bottom][right - i];

                //  move: [top -> bottom][right]
                matrix[bottom][right - i] = matrix[top + i][right];

                // move: [top][left -> right]
                matrix[top + i][right] = topLeft;
            }
            ++left;
            --right;
        }
    }
}