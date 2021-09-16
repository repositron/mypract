//
// Created by ljw on 16/09/21.
//

#include "../FindIfPathExistsGraph.h"
#include "gtest/gtest.h"

TEST(FindIfPathExistsGraph, TEST1 ) {
    std::vector<std::tuple<int, int>> adjacencyList
        {{0, 1}, {0, 2}, {3, 5,}, {5, 4}, {4, 3}};
    auto adjacency = FindIfPathExistsGraph::generate(6, adjacencyList);
    EXPECT_FALSE(FindIfPathExistsGraph::validPath(6, adjacency, 0, 5));
}

TEST(FindIfPathExistsGraph, Test2 ) {
    std::vector<std::tuple<int, int>> adjacencyList
            {{0, 1}, {0, 2}, {3, 5,}, {5, 4}, {4, 3}};
    auto adjacency = FindIfPathExistsGraph::generate(6, adjacencyList);
    EXPECT_EQ(FindIfPathExistsGraph::validPath(6, adjacency, 0, 5), false);
}
