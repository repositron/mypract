//
// Created by ljw on 26/01/21.
//

#include "../codility.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;

    TEST(binaryTree, Test1) {
        std::string s = "(2 , (1, 0, 0), 0)";
        auto t = codility::genTree(s);
        EXPECT_EQ(codility::solution(t), 2);
    }

    TEST(binaryTree, Test2apo) {
        std::string s = "(2 , (1, (1, 0, 0), (2,0,0)), 0)";
        auto t = codility::genTree(s);
        EXPECT_EQ(codility::solution(t), 3);
    }

    TEST(problem2, Test1) {

        std::vector<int> input1{1, 2, -3, 4, 5, -6 };
        EXPECT_EQ(codility::solution2(input1), 9);
    }

    TEST(problem2, Test2) {

        std::vector<int> input1{1};
        EXPECT_EQ(codility::solution2(input1), 1);
    }

    TEST(problem2, Test3) {

        std::vector<int> input1{0};
        EXPECT_EQ(codility::solution2(input1), 0);
    }

    TEST(problem2, Test4) {

        std::vector<int> input1{};
        EXPECT_EQ(codility::solution2(input1), -1);
    }

    TEST(problem2, Test5) {

        std::vector<int> input1{1, 2, -1, 1, 1};
        EXPECT_EQ(codility::solution2(input1), 3);
    }

    TEST(problem2, Test6) {

        std::vector<int> input1{1, 2, -1, 1, 5};
        EXPECT_EQ(codility::solution2(input1), 6);
    }


    TEST(problem2, Test7) {

        std::vector<int> input1{1, 2, -1, 6};
        EXPECT_EQ(codility::solution2(input1), 6);
    }

    TEST(problem2, Test8) {

        std::vector<int> input1{1, 2, 3};
        EXPECT_EQ(codility::solution2(input1), 6);
    }

 /*   TEST(problem2, Test5) {

        std::vector<int> input1{6};
        EXPECT_EQ(codility::solution(input1), -1);
    }

    TEST(problem2, Test6) {

        std::vector<int> input1{1, 0};
        EXPECT_EQ(codility::solution(input1), -1);
    }


    TEST(problem2, Test7) {

        std::vector<int> input1{1, 0, 0, 0, 4, 5};
        EXPECT_EQ(codility::solution(input1), 9);
    }
*/
    ///////
    TEST(problem1, Test1) {

        std::vector<long> input1{2, 5, 3, 6};
        EXPECT_EQ(codility::solution1(53, 1953786), 2);
    }

}