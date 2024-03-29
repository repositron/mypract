//
// Created by ljw on 12/12/20.
//

#include "../Graph.h"
#include "gtest/gtest.h"

using namespace std;
TEST(graphtest, Test1) {

    auto g = graphUtil::read("data/tinyCG.txt");
    EXPECT_EQ(g->numberEdges, 8);
    DepthFirstSearch dfs(*g, 0);
    EXPECT_TRUE(dfs.hasPathTo(5));
    auto path = dfs.pathTo(5);
}


TEST(graphtest, BreadFirstSearch) {

    auto g = graphUtil::read("data/tinyCG.txt");
    EXPECT_EQ(g->numberEdges, 8);
    BreadthFirstPaths bfs(*g, 0);
    EXPECT_TRUE(bfs.hasPathTo(5));
    auto path = bfs.pathTo(5);
    std::vector<int> myvect(10);
    //myvect.reserve(100)
    //std::sort(myvect.begin(), std::distance();
    // 2 1 1 2 3 1



}











std::vector<int> myvect(10);






