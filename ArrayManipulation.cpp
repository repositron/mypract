//
// Created by ljw on 13/09/20.
//
#include <bits/stdc++.h>
#include "ArrayManipulation.h"
namespace ArrayManipulation {


    // Complete the arrayManipulation function below.
    long arrayManipulation(int n, vector<vector<int>> queries) {
        vector<long> ar(n + 1, 0);


        for(auto& q: queries) {
            ar[q[0]] += q[2];
            if (q[1] + 1 <= n)
                ar[q[1] + 1] -= q[2];
        }
        long maxVal = 0;
        long acc = 0;
        for (int i = 1; i <= n; i++) {
            acc += ar[i];
            if (maxVal < acc)
                maxVal = acc;
        }
        return maxVal;
    }
};