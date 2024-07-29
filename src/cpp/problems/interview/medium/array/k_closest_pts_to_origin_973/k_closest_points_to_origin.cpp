#include "k_closest_points_to_origin.hpp"

#include <queue>

/**
 * Time Complexity: N * log(k)
 * Space Complexity: k
 */

namespace algo::interview::medium::array::k_closest_pt_to_origin {

    enum {
        X = 0,
        Y = 1
    };

    using Point = std::vector<int>;

    // distance squared from origin
    long d2O(Point const &a) {
        return a[X] * a[X] + a[Y] * a[Y];
    }

    struct PointComparator {
        bool operator()(Point const &a, Point const &b) {
            return d2O(a) < d2O(b);
        }
    };

    Matrix KClosestPointsToOrigin::kClosest(Matrix &points, int k) {
        // create a max pq
        std::priority_queue < Point, Matrix, PointComparator > maxPq;
        for (auto &pt: points) {
            maxPq.push(pt);
            if (maxPq.size() > k) {
                // pop the 'greater than' element
                maxPq.pop();
            }
        }

        // push in reverse order as we want minPq output and not maxPq
        Matrix closestPoints(k, {0, 0});
        while (not maxPq.empty()) {
            closestPoints[--k] = maxPq.top();
            maxPq.pop();
        }

        return closestPoints;
    }
}