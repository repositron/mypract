//
// Created by ljw on 16/09/21.
//


#include "../SortBalanceParentheses.h"
#include "gtest/gtest.h"

TEST(SortBalanceParentheses, Test1) {
    EXPECT_EQ(SortBalanceParentheses::balanceSort("(){}}"), "{()}");

}
