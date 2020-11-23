//
// Created by ljw on 22/08/20.
//

#include "gtest/gtest.h"
#include "../ParserUtil.h"
#include "../ChangeMaker.h"
#include "../Subset.h"
#include "../RodCutting.h"
#include "../Q1.h"
#include "../QX.h"
#include "../minSwaps.h"
#include "../MinBribes.h"
#include "../Rotate.h"
#include "../MaxSumArray.h"
#include "../MinAbs.h"
#include "../PairSum.h"
#include "TestUtil.h"

namespace {


   /* TEST(SampleTest, ParseDoublePair) {
        EXPECT_EQ(ParserUtil::convertDoublePair("129.34, 145.00"), std::make_tuple(12934, 14500));
    }

    TEST(SampleTest3, Change) {
        EXPECT_EQ(ChangeMaker::change(12934, 14500), "");
    }

    TEST(SampleTest4, Subset) {
        auto input = std::vector<int>({1, 3, 4});
        EXPECT_EQ(Subset::subset(input), std::vector<std::vector<int>>({{1,2}, {3}}));
    }

    TEST(SampleTest5, SubsetstR) {
        auto input = "abc";
        EXPECT_EQ(Subset::subsetStr(input), std::vector<std::string>({"a"}));
    }

    TEST(Cutting, ONe) {
        std::vector<int> inputA({1, 5, 8, 9, 10, 17, 17, 20});
        EXPECT_EQ(RodCutting::cutRod(inputA), 22);
    }*/

   TEST(MinAbs, Test1) {
        std::vector<int> input1({-59, -36, -13, 1, -53, -92, -2, -96, -54, 75});
        EXPECT_EQ(MinAbs::minimumAbsoluteDifference(input1), 1);
   }

    TEST(MinAbs, Test2) {
        std::vector<int> input1({-2, -1, 0, 1,});
        EXPECT_EQ(MinAbs::minimumAbsoluteDifference(input1), 1);
    }

    TEST(MaxSubsetArray, ONe2) {
        std::vector<int> inputA({3, 5, -7, 8, 10});
        EXPECT_EQ(MaxSumArray::maxSubsetSum(inputA), 15);
    }

    TEST(RotateLeft, ONe2) {
        std::vector<int> inputA({1, 2, 3, 4, 5});
        EXPECT_EQ(Rotate::rotLeft(inputA, 4), std::vector<int>({ 5, 1, 2, 3, 4}));
    }

    TEST(MinBribes, One) {
        auto tests = TestUtil::load("data/input06.txt");
        vector<int>& test0 = tests.at(0);
        EXPECT_EQ(MinBribes::minimumBribes1(test0), 7);

        std::vector<int> inputB({1, 2, 5, 3, 7, 8, 6, 4});
        EXPECT_EQ(MinBribes::minimumBribes1(inputB), 7);

        //EXPECT_EQ(minSwaps::minimumSwaps(std::vector<int>({})), 5);
    }

    TEST(PairSum, Test1) {
        std::vector<int> inputA({1, 2, 4, 4});
        EXPECT_TRUE(PairSum::isPairSum(inputA, 8));
    }

    TEST(PairSum, Test2) {
        std::vector<int> inputA({-5, -1,  2, 4, 9, 10, 11});
        EXPECT_TRUE(PairSum::isPairSum(inputA, 8));
    }

    TEST(PairSum, FailingTest) {
        std::vector<int> inputA({-5, -1,  2, 4, 10});
        EXPECT_FALSE(PairSum::isPairSum(inputA, 8));
    }

    TEST(Q1, ONe) {
        std::vector<int> inputA({10, 20, 7});
        EXPECT_EQ(Q1::minSum(inputA, 4), 22);
    }

    TEST(QX, ONe) {
        std::vector<int> inputB({3, 1, 3, 4});
        EXPECT_EQ(QX::hackerCards(inputB, 7), inputB);
    }

    TEST(minSwaps, One) {
        std::vector<int> inputB({2, 3, 4, 1, 5});
        EXPECT_EQ(minSwaps::minimumSwaps(inputB), 3);

        //EXPECT_EQ(minSwaps::minimumSwaps(std::vector<int>({})), 5);
    }
}