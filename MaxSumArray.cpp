//
// Created by ljw on 4/10/20.
//

#include "MaxSumArray.h"
#include <bits/stdc++.h>



namespace MaxSumArray {
    using namespace std;
    int maxSubsetSum0(const vector<int> arr) {
        if (arr.empty())
            return 0;
        int maxy = INT32_MIN;
        for (int i = 0; i < arr.size(); i++) {
            int m = maxSubsetSum0(vector<int>(arr.begin() + 1, arr.end()));
            maxy = std::max(m, maxy);
            maxy = std::max(m + arr[i], maxy);

        }
        return maxy;
    }

    int maxSubsetSum(vector<int> arr) {

        return maxSubsetSum0(arr);
    }
};