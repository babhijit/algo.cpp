#ifndef ALGO_CPP_LARGEST_ODD_NUM_IN_STR_HPP
#define ALGO_CPP_LARGEST_ODD_NUM_IN_STR_HPP

#include <string>

namespace algo::problems::leetcode::strings::largest_odd_num_in_str {

    class LargestOddNumberInString {
    public:
        std::string largestOddNumber(std::string num);

    private:
        static bool isOdd(int n) {
            return (n & 1) == 1;
        }
    };

}

#endif //ALGO_CPP_LARGEST_ODD_NUM_IN_STR_HPP
