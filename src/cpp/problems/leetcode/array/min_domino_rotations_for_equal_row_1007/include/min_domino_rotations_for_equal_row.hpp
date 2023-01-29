//
// Created by abhijit on 29/1/23.
//

#ifndef ALGO_CPP_MIN_DOMINO_ROTATIONS_FOR_EQUAL_ROW_HPP
#define ALGO_CPP_MIN_DOMINO_ROTATIONS_FOR_EQUAL_ROW_HPP

#include <vector>

namespace algo {
    namespace problems::leetcode::array::domino_min_rotations {

        class MinDominoRotationsForEqualRow {
        private:
            static constexpr int FACES = 6;

        public:
            int minDominoRotations(std::vector<int> &tops, std::vector<int> &bottoms);

            bool matchesPattern(int &topStartPattern, int &bottomStartPattern, const int topDie, const int bottomDie);
        };

    } // problems::leetcode::array::domino_min_rotations
} // algo

#endif //ALGO_CPP_MIN_DOMINO_ROTATIONS_FOR_EQUAL_ROW_HPP
