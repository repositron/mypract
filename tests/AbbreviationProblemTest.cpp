//
// Created by ljw on 14/01/21.
//


#include "../AbbreviationProblem.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;
    TEST(abbreviationProblemTest, Test1) {
        std::string a = "AbcDE";
        std::string b = "ABDE";
        EXPECT_EQ(AbbreviationProblem::abbreviation(a, b), "YES");
    }

    TEST(abbreviationProblemTest, Test2) {
        std::string a = "AbcDE";
        std::string b = "ABDEX";
        EXPECT_EQ(AbbreviationProblem::abbreviation(a, b), "NO");
    }

    TEST(abbreviationProblemTest, Test3) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("beFgH", "EFG"), "NO");
    }

    TEST(abbreviationProblemTest, Test5) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("abcdef", "ABCDEF"), "YES");
    }

    TEST(abbreviationProblemTest, Test6) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("abcZdef", "Z"), "YES");
    }

    TEST(abbreviationProblemTest, Test7) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("zabczdefz", "ZZZ"), "YES");
    }

    TEST(abbreviationProblemTest, Test8) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("AaA", "AA"), "YES");
    }

    TEST(abbreviationProblemTest, Test9) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("AaA", "AAAA"), "NO");
    }

    TEST(abbreviationProblemTest, Test10) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("BaaaaDB", "BAB"), "NO");
    }

    TEST(abbreviationProblemTest, Test11) {
        EXPECT_EQ(AbbreviationProblem::abbreviation("AbcBD", "ABD"), "YES");
    }
}