#pragma once

#include <vector>

namespace algo::interview::grind75::insert_interval {

    using IntMatrix = std::vector<std::vector<int>>;

    class InsertInterval {
    public:
        IntMatrix  insert(IntMatrix& intervals, std::vector<int>& newInterval);
    };

}