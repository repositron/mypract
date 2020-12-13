//
// Created by ljw on 6/12/20.
//

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

    /*long getWays(int n, vector<long> coins) {
        sort(coins.begin(), coins.begin());
        long dp[n + 1][coins.size() + 1];
        for (int i = 0; i < n + 1; i ++) {
            for (int c = 0; c < coins.size() + 1; c++) {
                if (i == 0 || c == 0)
                    dp[i][c] = 0;
                else {
                    if (n - c < 0)
                        dp[i][c] = dp[i-1][c];
                    else
                        dp[i][c] = dp[i -1][c] + 1;
                }
            }
        }
        long minCoins = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dp[i][coins.size()] < minCoins && 0 < dp[i][coins.size()]) {
                minCoins = dp[i][coins.size()];
            }
        }
        return minCoins;
    }*/
};