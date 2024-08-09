#include "include/ocean_view_buildings.hpp"

#include <deque>

namespace algo::interview::medium::stack::ocean_view_buildings {

    std::vector<int> OceanViewBuildings::findBuildings(std::vector<int> &heights) {
        std::deque<int> stack;

        for (std::size_t i = 0; i < heights.size(); ++i) {
            auto const& ht = heights[i];
            while (not stack.empty()) {
                auto idx = stack.back();
                auto const& lastHt = heights[idx];
                if (lastHt > ht) {
                    break;
                }
                stack.pop_back();
            }
            stack.push_back(i);
        }

        return {stack.begin(), stack.end()};
    }

}