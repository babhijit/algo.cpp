//
// Created by abhijit on 17/1/23.
//

#ifndef ALGO_CPP_BASE_LOADER_HPP
#define ALGO_CPP_BASE_LOADER_HPP

#include <filesystem>
#include <string>
#include <vector>

#include <boost/json.hpp>


class BaseLoader {

public:
    std::string load_file(const std::filesystem::path& file_name);
};


#endif //ALGO_CPP_BASE_LOADER_HPP
