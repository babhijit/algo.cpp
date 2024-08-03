#pragma once

#include <vector>
#include <utility>

namespace algo::interview::array::dot_prod_sparse_vector {

    class SparseVector {
        using KeyValue = std::pair<std::size_t, int>;
        using MykeyYourkey = std::pair<std::size_t, std::size_t>;
    public:
        explicit SparseVector(std::vector<int> &num);

        // Return the dotProduct of two sparse vectors
        int dotProduct(SparseVector& vec);

    private:
        [[nodiscard]] std::vector<MykeyYourkey> getCommonIndices(SparseVector const& other) const;

        [[nodiscard]] std::size_t size() const {
            return size_;
        }

    private:
        std::vector<KeyValue> sparseVector_;

        const std::size_t size_;
    };

}