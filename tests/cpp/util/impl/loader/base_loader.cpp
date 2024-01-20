//
// Created by abhijit on 17/1/23.
//

#include "loader/base_loader.hpp"

#include <fstream>


std::string BaseLoader::load_file(const std::filesystem::path &file_name) {
    std::ifstream in(file_name);
    if (!in.is_open()) {
        throw std::runtime_error(file_name.string() + std::string(" could not be opened"));
    }

    const auto sz = std::filesystem::file_size(file_name);
    std::string result(sz, '\0');
    in.read(result.data(), sz);

    return result;
}

std::string BaseLoader::operator()(const std::filesystem::path &file_name) {
    return load_file(file_name);
}
