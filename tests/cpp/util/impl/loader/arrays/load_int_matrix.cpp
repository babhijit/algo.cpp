#include "load_int_matrix.hpp"
#include "load_int_array.hpp"

#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

namespace algo::cpp::ds::tests::utils {

    IntMatrix LoadIntMatrix::operator()(boost::json::array &json_array) {
        LoadIntArray intArrayLoader;

        std::vector<std::vector<int>> result;
        for (auto &element: json_array) {
            result.push_back(intArrayLoader(element.as_array()));
        }
        return result;
    }

}