//
// Created by ljw on 16/11/20.
//

#include "MinAbs.h"

namespace MinAbs {
    using namespace std;

    int minimumAbsoluteDifference(vector<int> arr) {
        int minAbsValue = INT32_MAX;
        std::sort(arr.begin(), arr.end());
        for (auto i = 0; i < (arr.size() -1); i++) {
            int diff = std::abs(arr[i] - arr[i + 1]);
            if (diff < minAbsValue)
                minAbsValue = diff;
        }
        return minAbsValue;
    }

    int minimumAbsoluteDifferenceFirstVersion(vector<int> arr) {
        int minAbsValue = INT32_MAX;
        std::sort(arr.begin(), arr.end());
        for (auto i = 0; i < (arr.size() -1); i++) {
            for (auto j = i + 1; j < arr.size();  j++) {
                int diff = arr[i] - arr[j];
                minAbsValue = std::min(minAbsValue, std::abs(diff));
                if (0 <= diff)
                    break;
                if (minAbsValue == 0)
                    return minAbsValue;
            }
        }
        return minAbsValue;
    }
};