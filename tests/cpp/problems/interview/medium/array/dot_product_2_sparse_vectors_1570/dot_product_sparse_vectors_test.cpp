
#include "test_case.hpp"

#include "sparse_vector.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::array::dot_prod_sparse_vector;

class SparseVectorDotProductTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums1, std::vector<int> nums2, int expected) {
        SparseVector v1(nums1);
        SparseVector v2(nums2);
        auto result = v1.dotProduct(v2);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums1 = tc.getNums1();
        auto nums2 = tc.getNums2();
        auto expected = tc.getExpected();

        runTest(std::move(nums1), std::move(nums2), expected);
    }
};


TEST_F(SparseVectorDotProductTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "dot_product_2_sparse_vectors_1570";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
