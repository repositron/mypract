//
// Created by ljw on 18/11/20.
//

#include "PairSum.h"

namespace PairSum {

    bool isPairSum(const std::vector<int>& v, int sum) {
        int low = 0;
        int hi = v.size() - 1;
        while (low != hi) {
            int s = v[low] + v[hi];
            if (s == sum)
                return true;
            if (s < sum)
                low++;
            else
                hi--;
        }
        return false;
    }

};