//
// Created by ljw on 27/08/21.
//

#include "../removeduplicates.h"
#include "gtest/gtest.h"

namespace {

    using namespace std;
    TEST(RmoveDuplicates, Test1) {
        vector<int> data = {1, 1, 2};
        auto k = RemoveDuplicates::removeDuplicates(data);
        EXPECT_EQ(k, 2);
        EXPECT_EQ(vector<int>(data.begin(), next(data.begin(), k)), vector<int>({1, 2}));
    }

    TEST(RmoveDuplicates, Test2) {
        vector<int> data = {0, 0, 1, 1, 2, 2};
        auto k = RemoveDuplicates::removeDuplicates(data);
        EXPECT_EQ(k, 3);
        EXPECT_EQ(vector<int>(data.begin(), next(data.begin(), k)),
                vector<int>({0, 1, 2}));
    }

    TEST(RmoveDuplicates, Test3) {
        vector<int> data = {0, 0, 0};
        auto k = RemoveDuplicates::removeDuplicates(data);
        EXPECT_EQ(k, 1);
        EXPECT_EQ(vector<int>(data.begin(), next(data.begin(), k)),
                  vector<int>({0}));
    }

    TEST(RmoveDuplicates, NoDuplicates) {
        vector<int> data = {0, 1, 2};
        auto k = RemoveDuplicates::removeDuplicates(data);
        EXPECT_EQ(k, 3);
        EXPECT_EQ(vector<int>(data.begin(), next(data.begin(), k)),
                  vector<int>({0, 1, 2}));
    }
}
