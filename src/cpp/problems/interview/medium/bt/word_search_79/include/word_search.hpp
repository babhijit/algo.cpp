#pragma once

#include <utils/dstypedefs.hpp>

using namespace algo::cpp::ds::utils;

namespace algo::interview::medium::bt::word_search {

    class WordSearch {
    public:
        bool exist(Matrix<char>& board, std::string word);
    };

}