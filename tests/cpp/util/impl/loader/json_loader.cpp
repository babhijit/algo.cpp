#include "loader/json_loader.hpp"

#include "loader/base_loader.hpp"



boost::json::value JsonLoader::loadJson(std::filesystem::path const &path) {
    auto loader = BaseLoader();
    auto contents = loader.load_file(path);
    return boost::json::parse(contents);
}

boost::json::value JsonLoader::operator()(const std::filesystem::path &path) {
    return loadJson(path);
}
