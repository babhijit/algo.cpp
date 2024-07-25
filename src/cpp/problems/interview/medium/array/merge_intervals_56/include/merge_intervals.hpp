#ifndef ALGO_CPP_IV_ARRAY_MERGE_INTERVALS_HPP
#define ALGO_CPP_IV_ARRAY_MERGE_INTERVALS_HPP

#include <vector>

namespace algo::interview::medium::array::merge_intervals {

    using Row = std::vector<int>;
    using Matrix = std::vector<Row>;

    class MergeIntervals {
    public:
        Matrix merge(Matrix& intervls);
    };

}

#endif //ALGO_CPP_IV_ARRAY_MERGE_INTERVALS_HPP
