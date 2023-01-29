#include "min_domino_rotations_for_equal_row.hpp"

#include <algorithm>
#include <cassert>
#include <stdexcept>

namespace algo::problems::leetcode::array::domino_min_rotations {

    int MinDominoRotationsForEqualRow::minDominoRotations(std::vector<int> &tops,
                                                          std::vector<int> &bottoms) {

        assert(tops.size() == bottoms.size());
        assert(tops.size() > 0);

        const auto N = tops.size();

        int topCounts[FACES + 1] = {};
        int bottomCounts[FACES + 1] = {};

        auto topMostFreq = tops[0];
        ++topCounts[topMostFreq];

        auto bottomMostFreq = bottoms[0];
        ++bottomCounts[bottomMostFreq];

        // using the first element of *counts for tracking the starting pattern
        topCounts[0] = topMostFreq;
        bottomCounts[0] = bottomMostFreq;

        for (int i = 1; i < N; ++i) {
            auto const topDie = tops[i];
            auto const bottomDie = bottoms[i];
            if (!matchesPattern(topCounts[0], bottomCounts[0], topDie, bottomDie)) {
                return -1;
            }

            ++topCounts[topDie];
            if (topCounts[topDie] > topCounts[topMostFreq])
                topMostFreq = topDie;

            ++bottomCounts[bottomDie];
            if (bottomCounts[bottomDie] > bottomCounts[bottomMostFreq])
                bottomMostFreq = bottomDie;
        }

        int maxOccurences = std::max(topCounts[topMostFreq], bottomCounts[bottomMostFreq]);
        return N - maxOccurences;
    }

    bool MinDominoRotationsForEqualRow::matchesPattern(int &topStartPattern,
                                                       int &bottomStartPattern,
                                                       const int topDie,
                                                       const int bottomDie) {
        // check if topStartPattern pattern is broken
        if ((topDie != topStartPattern) && (bottomDie != topStartPattern))
            topStartPattern = 0;

        // check if bottomStartPattern pattern is broken
        if ((bottomDie != bottomStartPattern) && (topDie != bottomStartPattern))
            bottomStartPattern = 0;

        return bottomStartPattern || topStartPattern;
    }


} // algo::problems::leetcode::array::domino_min_rotations