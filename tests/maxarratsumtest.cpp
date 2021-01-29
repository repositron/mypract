//
// Created by ljw on 20/12/20.
//

#include "gtest/gtest.h"
#include "TestUtil.h"
#include <fstream>
#include "../MaxSumNoAdjacentArray.h"

namespace {
    using namespace std;
    vector<int> loadmaxdata(const string& path);

    TEST(maxsumarray, Test1) {
        std::vector<int> input1{3, -2, -5, 2, 5};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 8);
    }

    TEST(maxsumarray, Test2) {
        std::vector<int> input1{-1, -2, -5, -2, 5};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 5);
    }

    TEST(maxsumarray, Test3) {
        std::vector<int> input1{-1, -2, -5, -2, -5};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 0);
    }

    TEST(maxsumarray, Test4) {
        std::vector<int> input1{3, -2, 3, -2, 3, -2};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 9);
    }

    TEST(maxsumarray, Test5) {
        std::vector<int> input1{3, -2, 3, -2, 2, -2, -5};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 8);
    }

    TEST(maxsumarray, Test6) {
        std::vector<int> input1{2, 1, 2, 1, 2};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 6);
    }

    TEST(maxsumarray, Test7) {
        std::vector<int> input1{1, 2, 1, 2, 1};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 4);
    }

    TEST(maxsumarray, Test8) {
        std::vector<int> input1{2, 1, -2, 2};
        EXPECT_EQ(MaxSumNoAdjacentArray::maxSubsetSum(input1), 4);
    }

    TEST(maxsumarray, bigfile) {
        auto tests = loadmaxdata("data/maxsumdata4.txt");
        EXPECT_EQ(tests.size(), 18263);
        auto result = MaxSumNoAdjacentArray::maxSubsetSum(tests);
        EXPECT_EQ(result, 33450782);
    }

    vector<int> loadmaxdata(const string& path)
    {
        ifstream f(path);
        if (!f)
            return {};

        int n = 0;
        f >> n;

        f.ignore(numeric_limits<streamsize>::max(), '\n');

        //string arr_temp_temp;
        //getline(f, arr_temp_temp);

        //vector<string> arr_temp = TestUtil::split_string(arr_temp_temp);

        vector<int> arr;

        while (!f.eof()) {
            int value;
            f >> value;
            f >> std::ws;
            if (f.fail())
                throw runtime_error("damn");

            arr.push_back(value);
        }

        return arr;
    }
}