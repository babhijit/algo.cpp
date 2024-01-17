#include "uniq_occ.hpp"


#include <array>
#include <unordered_map>

namespace algo::problems::leetcode::hashtable::uniq_occurrences {

    bool UniqueOccurrences::uniqueOccurrences(std::vector<int> &integers) {
        std::unordered_map<int, std::size_t> frequencies;

        for (auto integer: integers) {
            auto& frequency = frequencies[integer];
            ++frequency;
        }

        constexpr int SIZE = 1'001;
        std::array<bool, SIZE> freqChecker{};
        for (auto itr = frequencies.begin(); itr != frequencies.end(); ++itr) {
            auto idx = itr->second;
            if (freqChecker[idx]) {
                return false;
            }
            freqChecker[idx] = true;
        }

        return true;
    }
}