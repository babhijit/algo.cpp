#pragma once

#include <string>
#include "load_t_array.hpp"


namespace algo::cpp::ds::tests::utils {

    struct StringTransformer {
        std::string operator()(boost::json::value& jsonStr) {
            return std::string(jsonStr.as_string().c_str());
        }
    };

    using LoadStrArray = LoadTArray<std::string, StringTransformer>;

}
