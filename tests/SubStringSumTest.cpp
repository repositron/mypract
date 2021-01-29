//
// Created by ljw on 23/01/21.
//

#include "../SubStringSum.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;
    TEST(SubString, Test1) {
        EXPECT_EQ(SubStringSum::substrings("123"), 164);
    }

    TEST(SubString, Test2) {
        EXPECT_EQ(SubStringSum::substrings("972698438521"), 445677619);
    }


}