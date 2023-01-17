#ifndef ALGO_CPP_MAPPER_HPP
#define ALGO_CPP_MAPPER_HPP

#include <boost/json/src.hpp>

namespace algo::cpp::ds::tests::utils {

    template <typename T>
    class Mapper {
    public:
        T to_object(boost::json::value& json);
    };

}


#endif //ALGO_CPP_MAPPER_HPP
