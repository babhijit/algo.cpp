#pragma once

#include <utils/dstypedefs.hpp>

#include <string>
#include <vector>

namespace algo::interview::medium::string::group_anagrams {

    using namespace algo::cpp::ds::utils;

    class GroupAnagram {
    public:
        Matrix<std::string> groupAnagrams(std::vector<std::string>& strings);
    };

}
