#include "next_perm.hpp"

#include <algorithm>

namespace algo::interview::medium::array::next_perm_31 {

    class Impl {
        using VecItr = std::vector<int>::iterator;

    public:
        explicit Impl(std::vector<int> &nums) : nums_(nums) {}

        void nextPermutation() {
            auto start = nums_.begin();
            auto end = nums_.end();

            auto pivot = getPivot(start, end);
            if (pivot != start) {
                auto target = std::prev(pivot);
                auto ub = std::prev(end);
                while (ub != pivot) {
                    if (*target < *ub) {
                        break;
                    }
                    --ub;
                }
                std::iter_swap(ub, target);
            }

            std::reverse(pivot, end);
        }

    private:
        static VecItr upperBound(VecItr begin, VecItr end, int target) {
            auto ub = end;
            while (begin != end) {
                auto length = std::distance(begin, end);
                auto half = length/2;
                auto mid = std::next(begin, half);
                if (*mid > target) {
                    ub = mid;
                    begin = ++mid;
                } else {
                    end = mid;
                }
            }

            return ub;
        }

    private:
        static VecItr getPivot(VecItr start, VecItr end) {
            auto itr = --end;
            while (itr != start) {
                auto prev = std::prev(itr);
                if (*prev < *itr) {
                    break;
                }
                itr = prev;
            }
            return itr;
        }


    private:
        std::vector<int> &nums_;
    };

    void NextPermutation::nextPermutation(std::vector<int> &nums) {
        Impl helper(nums);
        helper.nextPermutation();
    }
}