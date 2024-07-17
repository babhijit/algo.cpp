#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include "loader/base_loader.hpp"


namespace algo::cpp::ds::tests::utils {
    class LoadIntArray : public BaseLoader {
    public:
        std::vector<int> operator()(std::string input);
        std::vector<int> operator()(boost::json::array& json_array);
    };
}
