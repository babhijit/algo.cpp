#pragma once

#include <string>
#include <vector>

namespace algo::problems::leetcode::strings::find_index_of_str_28 {

    class FindIndexOfString {
    public:
        int strStr(std::string const& haystack, std::string const& needle);

    private:
        std::vector<int> getLps(std::string const& pattern);
    };

}