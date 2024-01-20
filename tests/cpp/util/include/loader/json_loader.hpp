#pragma once

#include <boost/json.hpp>

#include <filesystem>

class JsonLoader {
public:
    boost::json::value loadJson(std::filesystem::path const &path);
    boost::json::value operator()(std::filesystem::path const &path);
};