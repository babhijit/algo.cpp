#include <gtest/gtest.h>


#include <digraph/digraph.hpp>
#include <digraph/directed_cycle.hpp>

#include <ds_loader_utils.hpp>
#include <stl_compare_utils.hpp>

using namespace algo::cpp::ds;
using namespace algo::cpp::ds::tests;

class DirectedCycleTests : public ::testing::Test {

protected:
    std::unique_ptr<Digraph> G_;
    std::unique_ptr<DirectedCycle> directed_cycle_;

protected:

    void SetUp() override {
    }

    void TearDown() override {
        directed_cycle_.reset();
        G_.reset();
    }

    void load_structures(const std::string& filename) {
        auto G = utils::load_digraph(filename);
        G_ = std::make_unique<Digraph>(std::move(G));
        directed_cycle_ = std::make_unique<DirectedCycle>(*G_);
    }
};


TEST_F(DirectedCycleTests, DGHasCycle) {
    load_structures("tinyDG.txt");

    ASSERT_TRUE(container_value_equals(std::vector<int>{3, 5, 4, 3}, directed_cycle_->cycle()));
}

TEST_F(DirectedCycleTests, DGHasNoCycle) {
    load_structures("tinyDGNoCycle.txt");

    ASSERT_FALSE(directed_cycle_->has_cycle());
}