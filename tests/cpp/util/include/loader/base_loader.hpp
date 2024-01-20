#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <boost/json.hpp>


class BaseLoader {

public:
    std::string load_file(const std::filesystem::path &file_name);
    std::string operator()(const std::filesystem::path &file_name);
};
