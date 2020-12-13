//
// Created by ljw on 28/11/20.
//

#include "../KnapsackProblem.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;
    TEST(knapsack, Test1) {

        std::vector<std::vector<int>> input1{{1, 2}, {4, 3}, {5, 6}, {6, 7}};
        std::vector<std::vector<int>> vector1S{{10}, {1, 3}};
        EXPECT_EQ(KnapsackProblem::knapsackProblem(input1, 10), vector1S);
    }
}