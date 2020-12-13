//
// Created by ljw on 26/11/20.
//
#include "../WaterArea.h"
#include "gtest/gtest.h"

namespace {


    TEST(waterAreaDp, Test2) {
        std::vector<int> input1{5, 0, 6};
        EXPECT_EQ(WaterArea::waterAreaDp(input1), 5);
    }

    TEST(waterAreaDp, Test3) {
        std::vector<int> input1{10, 0, 0, 5};
        EXPECT_EQ(WaterArea::waterAreaDp(input1), 10);
    }

    TEST(waterAreaDp, Test1) {
        std::vector<int> input1{0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};
        EXPECT_EQ(WaterArea::waterAreaDp(input1), 48);
    }

    TEST(waterAreaDp, edgeCase1) {
        std::vector<int> input1{ 0 };
        EXPECT_EQ(WaterArea::waterAreaDp(input1), 0);
    }

    TEST(waterAreaDp, edgeCase2) {
        std::vector<int> input1{ 0, 1, 0 };
        EXPECT_EQ(WaterArea::waterAreaDp(input1), 0);
    }


}