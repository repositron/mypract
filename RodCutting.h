//
// Created by ljw on 30/08/20.
//

#ifndef MYPRACT_RODCUTTING_H
#define MYPRACT_RODCUTTING_H

#include <climits>
#include <vector>

struct RodCutting {
    static int cutRod(const std::vector<int>& price) {
        const int n = price.size();
        int val[n+1];
        val[0] = 0;
        int i, j;
        // Build the table val[] in bottom up manner and return the last entry
        // from the table
        for (i = 1; i<=n; i++)
        {
            int max_val = INT_MIN;
            for (j = 0; j < i; j++)
                max_val = std::max(max_val, price[j] + val[i-j-1]);
            val[i] = max_val;
        }
        return val[n];
    }
};


#endif //MYPRACT_RODCUTTING_H
