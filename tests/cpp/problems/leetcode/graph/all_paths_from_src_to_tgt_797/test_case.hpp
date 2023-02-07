#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"

#include "loader/arrays/load_int_array.hpp"

using namespace algo::problems::leetcode::graph::all_paths_from_src_to_tgt;

class TestCase {
    using Graph = AllPathsFromSourceToTarget::Graph;

private:
    Graph input;
    Graph expected;

public:
    TestCase(std::filesystem::path testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = load_dag(json.at("input").as_array());
        expected = load_dag(json.at("expected").as_array());
    }

    [[nodiscard]] Graph getExpected() const {
        return expected;
    }


    [[nodiscard]] Graph getInput() const {
        return input;
    }

private:
    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }

    static Graph load_dag(boost::json::array json_matrix) {
        Graph result;
        for(auto &element: json_matrix) {
            auto row = load_vector(element.as_array());
            result.push_back(row);
        }

        return result;
    }

};


#endif //ALGO_CPP_TEST_CASE_HPP
