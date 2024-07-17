#pragma once

#include <vector>

namespace algo::interview::grind75::update_matrix_01 {

    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    class UpdateMatrix {
    public:
        Matrix<int> updateMatrix(Matrix<int>& mat);
    };

}