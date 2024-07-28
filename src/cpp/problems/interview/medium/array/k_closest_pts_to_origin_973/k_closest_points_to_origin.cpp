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
        std::priority_queue < Point, Matrix, PointComparator > pq;
        for (auto &pt: points) {
            pq.push(pt);
            if (pq.size() > k) {
                // pop the 'greater than' element
                pq.pop();
            }
        }

        // push in reverse order
        Matrix closestPoints(k, {0, 0});
        while (not pq.empty()) {
            closestPoints[--k] = pq.top();
            pq.pop();
        }

        return closestPoints;
    }
}