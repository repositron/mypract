//
// Created by ljw on 20/12/20.
//

#include <iostream>
#include "MaxSumNoAdjacentArray.h"


namespace MaxSumNoAdjacentArray {
    int maxSubsetSum(vector<int> arr) {
        if (arr.size() == 0)
            return 0;
        if (arr.size() == 1)
            return max(arr[0], 0) ;

        int64_t prevprev = max(arr[0], 0);
        int64_t prev = arr[1] < 0 ? prevprev : arr[1];

        for  (vector<int>::size_type i = 2; i < arr.size(); i++) {
            int val1 = 0;

            if (0 < arr[i]) {
                val1 = prevprev + arr[i];
                prevprev = prev;
                prev = val1;
            }
            else {
                prev = max(prevprev, prev); // skipping arr[i]
                prevprev = prev;

            }
            std::cout << prevprev << " " << prev << std::endl;
        }
        return max(prevprev, prev);
    }
};
