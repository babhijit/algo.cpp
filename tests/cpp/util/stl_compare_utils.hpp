#ifndef ALGO_CPP_STL_COMPARE_UTILS_HPP
#define ALGO_CPP_STL_COMPARE_UTILS_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

template<class FirstContainer, class SecondContainer, class BinaryPredicate = std::equal_to<>>
bool container_value_equals(const FirstContainer& first, const SecondContainer& second, BinaryPredicate predicate = BinaryPredicate{}) {
    if(first.size() != second.size())    return false;

    return std::equal(std::begin(first), std::end(first),
                      std::begin(second), std::end(second),
                      predicate);
}

template <typename ForwardIterator,
         typename T = typename std::iterator_traits<ForwardIterator>::value_type>
std::string to_string(ForwardIterator first, ForwardIterator last,
                      std::function<std::string(T)> t_to_string = std::to_string,
                      const std::string& delimiter = " ") {
    std::ostringstream oss;
    for (auto it = first; it != last; ++it) {
        oss << t_to_string(*it) << delimiter;
    }

    return oss.str();
}


#endif //ALGO_CPP_STL_COMPARE_UTILS_HPP
