#pragma once

#include <utils/dstypedefs.hpp>

#include <string>

using namespace algo::cpp::ds::utils;

namespace algo::interview::bfs_dfs::acc_merge {

    class AcctMerge {
    public:
        Matrix<std::string> accountsMerge(Matrix<std::string>& accounts);
    };

}