#pragma once

#include "nested_integer.hpp"

#include <vector>

namespace algo::interview::medium::array::nested_list_weighted_sum {

    class NestedListWeightedSum {
    public:
        int depthSum(std::vector<NestedInteger>& nestedList);
    };
}