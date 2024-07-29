#pragma once

#include "load_t_array.hpp"

#include "loader/base_loader.hpp"

#include "utils/dstypedefs.hpp"

#include <filesystem>
#include <string>
#include <vector>


namespace algo::cpp::ds::tests::utils {

    using namespace algo::cpp::ds::utils;

    template<typename T, typename Transformer>
    class LoadTMatrix : public BaseLoader {
    private:
        Transformer transformer_;

    public:
        LoadTMatrix() : transformer_{} {}
        explicit LoadTMatrix(Transformer transformer) : transformer_(std::move(transformer)) {}

    public:
        Matrix<T> operator()(boost::json::array& json_array) {
            LoadTArray<T, Transformer> tArrayLoader(transformer_);

            Matrix<T> result;
            for (auto &element: json_array) {
                result.push_back(tArrayLoader(element.as_array()));
            }
            return result;
        }
    };
}

