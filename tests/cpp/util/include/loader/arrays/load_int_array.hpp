//
// Created by abhijit on 17/1/23.
//

#ifndef ALGO_CPP_LOAD_ARRAY_HPP
#define ALGO_CPP_LOAD_ARRAY_HPP

#include <filesystem>
#include <string>
#include <vector>
#include "loader/base_loader.hpp"


namespace algo::cpp::ds::tests::utils {
    class LoadIntArray : public BaseLoader {
    public:
        std::vector<int> operator()(std::string input);
    };
}

#endif //ALGO_CPP_LOAD_ARRAY_HPP
