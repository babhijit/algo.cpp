#ifndef ALGO_CPP_NEXT_PERMUTATION_HPP
#define ALGO_CPP_NEXT_PERMUTATION_HPP

#include <functional>
#include <vector>

namespace algo::problems::leetcode::array::next_permutation {

    class NextPermutation {
        using IntVecItr = std::vector<int>::iterator;

    private:
        std::less<int> less;

    private:
        IntVecItr getGreatestFromEnd(std::vector<int> &nums);

        IntVecItr getNextGreater(IntVecItr first, IntVecItr last, int value);

    public:
        void nextPermutation(std::vector<int> &nums);
    };

} // algo::problems::leetcode::array::next_permutation

#endif //ALGO_CPP_NEXT_PERMUTATION_HPP
