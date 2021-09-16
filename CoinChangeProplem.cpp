//
// Created by ljw on 6/12/20.
//

#include <iostream>
#include "CoinChangeProplem.h"

namespace CoinChangeProblem {

    long getMinWays(int n, vector<long> coins) {
        long max = n + 1;
        long dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++)
            dp[i] = max;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }

    // https://www.hackerrank.com/challenges/coin-change/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
    long getWays(int n, vector<long> coins) {
        long dp[n + 1][coins.size() + 1];
        for (int c = 0; c < coins.size() + 1; c++) {
            for (int i = 0; i < n + 1; i ++) {
                if (i == 0)
                    dp[i][c] = 1;
                else if (c == 0)
                    dp[i][c] = 0;
                else {
                    long prev = dp[i][c - 1];
                    if (0 <= i - coins[c -1])
                        dp[i][c] = prev + dp[i - coins[c -1]][c];
                    else
                        dp[i][c] = prev;
                }
                std::cout << "dp[" << i << "][" << c << "] = " << dp[i][c] << ";\n";
            }
        }
        return dp[n][coins.size()];
    }
};