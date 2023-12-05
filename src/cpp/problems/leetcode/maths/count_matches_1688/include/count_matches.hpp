#ifndef ALGO_CPP_COUNT_MATCHES_HPP
#define ALGO_CPP_COUNT_MATCHES_HPP

namespace algo::problems::leetcode::maths::count_matches {

    class CountMatches {
    public:
        int numberOfMatches(int n);

    private:
        bool isEven(int n) {
            return (n & 1) == 0;
        }
    };

}

#endif //ALGO_CPP_COUNT_MATCHES_HPP
