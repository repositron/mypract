//
// Created by ljw on 13/06/21.
//

#include "gtest/gtest.h"
#include "../CousinsBinaryTree.h"

namespace {
    TEST(cousins, Test1) {
        using namespace CousinsBinaryTree;
        auto nodeList = populate({1, 2, 3, 4}, 0);
        EXPECT_TRUE(isCousins(nodeList, 3, 4));

    }
}