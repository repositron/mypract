//
// Created by ljw on 21/11/20.
//

#include "gtest/gtest.h"
#include "../CountRectangles.h"
#include <vector>

namespace {
    class CountRectanglesTest : public ::testing::Test {
    protected:

        CountRectanglesTest() {
        }

        ~CountRectanglesTest() override {
        }

        void SetUp() override {
            const std::vector<CountRectangles::Point> uP = {
                    {5,1}, {5,4}, {1, 4}, {1, 1}, {2, 2}
            };
            unsortedPoints = uP;
        }

        void TearDown() override {
        }

        std::vector<CountRectangles::Point> unsortedPoints;
    };

    TEST_F(CountRectanglesTest, Test1) {


        std::vector<CountRectangles::Point> points{
            {2, 8}};
        EXPECT_EQ(CountRectangles::countRectangles(points), 1);
    }

    TEST_F(CountRectanglesTest, Sort) {
        CountRectangles::sort(unsortedPoints);
        std::vector<CountRectangles::Point> expected = {
                {1,1}, {1, 4}, {2, 2}, {5, 1}, {5, 4}
                           };
        for (int i = 0; i < expected.size(); ++i) {
            EXPECT_EQ(expected[i].x, unsortedPoints[i].x) << "x differ at index " << i;
            EXPECT_EQ(expected[i].y, unsortedPoints[i].y) << "y differ at index " << i;
        }
    }

};