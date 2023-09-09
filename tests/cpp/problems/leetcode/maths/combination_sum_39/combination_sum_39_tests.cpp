#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include <combination_sum.h>

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"
#include "loader/base_loader.hpp"


using namespace algo::problems::leetcode::maths::combination_sum;

class CombinationSumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static bool vectorsEq(CombinationSum::IntRowVector &a, CombinationSum::IntRowVector &b) {
        if (a.size() != b.size()) {
            return false;
        }

        for (std::size_t i{0}; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    };

    void runTestCase(std::vector<int> &candidates, int target, CombinationSum::IntMatrix &expected) {
        auto actual = solution.combinationSum(candidates, target);

        // solution can be in any order
        std::sort(std::begin(actual), std::end(actual));
        std::sort(std::begin(expected), std::end(expected));

        for (int i = 0; i < actual.size(); ++i) {
            ASSERT_TRUE(vectorsEq(actual[i], expected[i]));
        }
    }

    void sortMatrix(CombinationSum::IntMatrix &matrix) {
        // first do a row-wise sorting
        for (auto& row: matrix) {
            std::sort(std::begin(row), std::end(row));
        }

        // now sort the matrix
        auto columnSort = [](std::vector<int> const& a, std::vector<int> const& b) -> bool {
            auto sz = a.size();
            for (auto i = 0; i < sz; ++i) {
                if (a[i] > b[i])        return true;
                else if (a[i] < b[i])   return false;
            }
            return true;
        };

        std::sort(std::begin(matrix), std::end(matrix), columnSort);
    }

private:
    CombinationSum solution;
};


TEST_F(CombinationSumTests, TwoCombinations) {
    std::vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    CombinationSum::IntMatrix expected{{2, 2, 3},
                                       {7}};

    runTestCase(candidates, target, expected);
}

TEST_F(CombinationSumTests, NoCombinations) {
    std::vector<int> candidates{2};
    int target = 1;
    CombinationSum::IntMatrix expected;

    runTestCase(candidates, target, expected);
}

TEST_F(CombinationSumTests, ThreeCombinations) {
    std::vector<int> candidates{2, 3, 5};
    int target = 8;
    CombinationSum::IntMatrix expected{{2, 2, 2, 2},
                                       {2, 3, 3},
                                       {3, 5}};

    runTestCase(candidates, target, expected);
}

