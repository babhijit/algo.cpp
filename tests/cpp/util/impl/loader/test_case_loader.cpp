#include <algorithm>
#include <utility>
#include "test_case_loader.hpp"

void TestCaseLoader::operator()(std::filesystem::path &directoryPath,
                                std::function<void(const std::filesystem::directory_entry &)> testRunner) {
    loadTestCase(directoryPath, std::move(testRunner));
}

void TestCaseLoader::loadTestCase(std::filesystem::path &directoryPath, TestCaseLoader::TestRunner testRunner) {
    std::for_each(std::filesystem::directory_iterator(directoryPath),
                  std::filesystem::directory_iterator(),
                  std::move(testRunner));
}
