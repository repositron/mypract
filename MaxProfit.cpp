//
// Created by ljw on 6/12/20.
//

#include <vector>


/*This problem was asked by Facebook.
Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once.
 You must buy before you can sell it.
For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/

// O(n) space and complexity
namespace MaxProfit {
    using namespace std;
    int maxProfit(vector<int> prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int maxSell[n];
        maxSell[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSell[i] = max(maxSell[i + 1], prices[i]);
        }
        int maxProfitTmp = 0;
        for (int i = 0; i < n; i++) {
            int profit = maxSell[i] - prices[i];
            if (maxProfitTmp < profit)
                maxProfitTmp = profit;
        }
        return maxProfitTmp;

    }
};