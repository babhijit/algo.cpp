#pragma once

#include "load_int_array.hpp"

#include "loader/base_loader.hpp"

#include <filesystem>
#include <string>
#include <vector>


namespace algo::cpp::ds::tests::utils {
    using IntMatrix = std::vector<std::vector<int>>;

    class LoadIntMatrix : public BaseLoader {
    public:
        IntMatrix operator()(boost::json::array& json_array);
    };
}

