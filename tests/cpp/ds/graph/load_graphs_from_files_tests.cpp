#include <filesystem>

#include <gtest/gtest.h>

#include <graph/graph.hpp>


/**
 * Loads Graph from txt files and simply checks they have been loaded properly or not
 */
class LoadGraphsFromFilesTest : public ::testing::Test {
protected:
    using IntGraph = algo::cpp::ds::Graph<int>;
    
protected:
    void SetUp() override {}
    
    void TearDown() override {}
    
protected:
    static std::filesystem::path get_file_path(const std::string& file_name) {
        namespace fs = std::filesystem;
        auto path = fs::current_path();

        path /= "tests";
        path /= "resources";
        path /= "ds";
        path /= "graph";
        path /= file_name;

        return path;
    }
};


TEST_F(LoadGraphsFromFilesTest, LoadTinyGTest) {
    const std::filesystem::path tinyGPath = get_file_path("tinyG.txt");
    IntGraph G = algo::cpp::ds::load_graph_from_file<int>(tinyGPath);
    ASSERT_EQ(13, G.V());
    ASSERT_EQ(13, G.E());
}

TEST_F(LoadGraphsFromFilesTest, LoadMediumGTest) {
    const std::filesystem::path mediumGPath = get_file_path("mediumG.txt");
    IntGraph G = algo::cpp::ds::load_graph_from_file<int>(mediumGPath);
    ASSERT_EQ(250, G.V());
    ASSERT_EQ(1273, G.E());
}

