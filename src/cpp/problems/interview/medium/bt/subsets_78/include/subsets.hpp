#pragma once

#include <utils/dstypedefs.hpp>

#include <vector>


namespace algo::interview::medium::bt::subsets {

    using namespace algo::cpp::ds::utils;

    class Subsets {
    public:
        Matrix<int> subsets(std::vector<int>& nums);
    };
}

