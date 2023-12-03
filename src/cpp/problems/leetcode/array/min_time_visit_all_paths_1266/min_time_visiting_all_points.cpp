#include "min_time_visiting_all_points.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::min_time_visiting_all_points {

    int MinTimeVisitingAllPoints::minTimeToVisitAllPoints(std::vector<std::vector<int>> &points) {

        if (points.empty()) {
            throw std::invalid_argument("points should not be empty");
        }

        int time{};
        for (int i = 1; i < points.size(); ++i) {
            auto [x1, y1] = std::pair{points[i - 1][0], points[i - 1][1]};
            auto [x2, y2] = std::pair{points[i][0], points[i][1]};
            time += std::max(std::abs(x2 - x1), std::abs(y2 - y1));
        }

        return time;
    }


} // namespace algo::problems::leetcode::array::min_time_visiting_all_points