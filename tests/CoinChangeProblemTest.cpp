//
// Created by ljw on 6/12/20.
//

#include "../CoinChangeProplem.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;

    TEST(coinchangeproblemtestGetways, Test2) {

        std::vector<long> input1{2};
        EXPECT_EQ(CoinChangeProblem::getWays(2, input1), 1);
    }

    TEST(coinchangeproblemtestGetways, Test1) {

        std::vector<long> input1{2, 5, 3, 6};
        EXPECT_EQ(CoinChangeProblem::getWays(10, input1), 5);
    }

    TEST(coinchangeproblemtest, Test1) {

        std::vector<long> input1{2, 5, 3, 6};
        EXPECT_EQ(CoinChangeProblem::getMinWays(10, input1), 5);
    }

    TEST(coinchangeproblemtest, Test2) {

        std::vector<long> input1{2, 6};
        EXPECT_EQ(CoinChangeProblem::getMinWays(6, input1), 1);
    }
}