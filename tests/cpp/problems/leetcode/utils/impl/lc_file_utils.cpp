#include "lc_file_utils.hpp"
#include "res/test_resource_utils.hpp"

namespace algo::cpp::ds::tests::utils::leetcode {

    std::filesystem::path get_test_leetcode_dir() {
        return get_test_resource_dir("leetcode");
    }

    std::filesystem::path get_test_ds_dir(const std::string &ds_type) {
        auto leetcode_dir = get_test_leetcode_dir();
        return leetcode_dir / ds_type;
    }
}
