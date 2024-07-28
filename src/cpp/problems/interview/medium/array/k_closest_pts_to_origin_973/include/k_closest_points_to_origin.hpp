#pragma once

#include <vector>

namespace algo::interview::medium::array::k_closest_pt_to_origin {

    using Matrix = std::vector<std::vector<int>>;

    class KClosestPointsToOrigin {
    public:
        Matrix kClosest(Matrix& points, int k);
    };

}