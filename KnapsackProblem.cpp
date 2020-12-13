//
// Created by ljw on 28/11/20.
//

#include "KnapsackProblem.h"

#include <array>
#include <iostream>

namespace KnapsackProblem {
    void print2DArray(int** a, int n, int c) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << std::to_string(a[i][j]) + " ";
            }
        }
    }


    // {1, 2}, {4, 3}, {5, 6}, {6, 7}}  --- {v,w}
    vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
        vector<vector<int>> answer;
        int n = items.size();
        int dpArray[n + 1][capacity + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int w = 0; w < capacity + 1; w++) {
                if (i == 0 || w == 0)
                    dpArray[i][w] = 0;
                else {
                    int totalVal1 = items[i][0] + dpArray[i-1][w-items[i][1]];
                    if (items[i][1] <= w)
                            dpArray[i - 1][w];
                    else {
                        int profit1 = 0;
                        if (items[i][1] <= w)
                            profit1 = items[i][0] + dpArray[i - 1][w - items[i][1]];
                        int profit2 = dpArray[i - 1][w];
                        dpArray[i][w] = std::max(profit1, profit2);
                    }
                }
            }
        }

        int totalProfit = dpArray[n][capacity];

        return answer;
    }
};