#pragma once

#include <utils/dstypedefs.hpp>

#include <vector>


namespace algo::interview::medium::bt::subsets_ii {

    using namespace algo::cpp::ds::utils;

    class Subsets {
    public:
        Matrix<int> subsetsWithDup(std::vector<int>& nums);
    };
}

