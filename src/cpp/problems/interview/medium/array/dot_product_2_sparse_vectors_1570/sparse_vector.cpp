#include "sparse_vector.hpp"

#include <cassert>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(L)
 */

namespace algo::interview::array::dot_prod_sparse_vector {

    SparseVector::SparseVector(std::vector<int> &num) : size_(num.size()) {
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != 0) {
                sparseVector_.emplace_back(i, num[i]);
            }
        }
    }

    int SparseVector::dotProduct(SparseVector &vec) {
        assert ((vec.size() == size()) and "Size of both sparse vectors must match");

        int product{0};

        auto commonIndices = getCommonIndices(vec);
        for (auto [myItr, yourItr]: commonIndices) {
            auto& myValue = sparseVector_[myItr].second;
            auto& yourValue = vec.sparseVector_[yourItr].second;
            product += (myValue * yourValue);
        }

        return product;
    }

    std::vector<SparseVector::MykeyYourkey> SparseVector::getCommonIndices(SparseVector const& other) const {
        std::vector<MykeyYourkey> commonIndices;

        std::size_t myItr{0};
        std::size_t yourItr{0};

        while ((myItr < sparseVector_.size()) and (yourItr < other.sparseVector_.size())) {
            auto& myIndex = sparseVector_[myItr].first;
            auto& yourIndex = other.sparseVector_[yourItr].first;
            if (myIndex == yourIndex) {
                commonIndices.emplace_back(myItr, yourItr);
                ++myItr;
                ++yourItr;
            } else if (myIndex < yourIndex) {
                ++myItr;
            } else {
                ++yourItr;
            }
        }

        return commonIndices;
    }
}