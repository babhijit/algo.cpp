#pragma once

#include "load_str_array.hpp"

#include "load_t_matrix.hpp"

#include <string>


namespace algo::cpp::ds::tests::utils {

    using LoadStrMatrix = LoadTMatrix<std::string, StringTransformer>;

}

