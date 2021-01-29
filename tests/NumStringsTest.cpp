//
// Created by ljw on 1/01/21.
//

#include "../NumStrings.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;
    TEST(NumStrings, Test1) {
        std::string input1("niesevehrtfeev");
        EXPECT_EQ(NumStrings::unanagram(input1), "357");
    }


}