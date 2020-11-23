//
// Created by ljw on 13/09/20.
//

#include "gtest/gtest.h"
#include "../ArrayManipulation.h"
#include <vector>

namespace {


    TEST(ArryaManipulation, TestCase2) {
        std::vector<std::vector<int>> queries{
            {2, 6, 8}, {3, 5, 7}, {1, 8, 1,}, {5, 9, 15}};
        EXPECT_EQ(ArrayManipulation::arrayManipulation(10, queries), 31);
    }
};