#include "update_matrix.hpp"

#include "update_matrix_dp.hpp"
#include "update_matrix_bfs.hpp"

/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */

namespace algo::interview::grind75::update_matrix_01 {

    Matrix<int> UpdateMatrix::updateMatrix(Matrix<int> &mat) {
//        dp::UpdateMatrix updateMatrixDp;
        bfs::UpdateMatrix updateMatrixBfs;
        return updateMatrixBfs(mat);
    }
}