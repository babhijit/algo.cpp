#include "load_int_array.hpp"

#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

namespace algo::cpp::ds::tests::utils {
    std::vector<int> LoadIntArray::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        std::vector<int> integers;
        std::transform(std::begin(values), std::end(values),
                       std::back_inserter(integers),
                       [](std::string s) { return boost::lexical_cast<int>(s); });

        return integers;
    }

    std::vector<int> LoadIntArray::operator()(boost::json::array &json_array) {
        std::vector<int> integers;
        std::transform(std::begin(json_array), std::end(json_array),
                       std::back_inserter(integers),
                       [](auto &element) { return element.get_int64(); });

        return integers;
    }

}