#ifndef ALGO_CPP_UTILS_DS_NOT_IMPLEMENTED_HPP
#define ALGO_CPP_UTILS_DS_NOT_IMPLEMENTED_HPP

#include <stdexcept>

namespace algo::cpp::ds::utils {

    class NotImplemented : public std::logic_error {
    public:
        NotImplemented() : std::logic_error("Not Implemented!") {}
    };

}

#endif //ALGO_CPP_UTILS_DS_NOT_IMPLEMENTED_HPP
