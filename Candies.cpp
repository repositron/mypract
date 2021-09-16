//
// Created by ljw on 9/02/21.
//

#include "Candies.h"


namespace Candies {
    using namespace  std;
    long candies(int n, std::vector<int> arr) {
        std::vector<int> l(n);
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i])
                l[i] = l[i - 1] + 1;
            else
                l[i] = 1;
        }
        std::vector<int> r(n);
        int r1 = 1;
        /*for (int i = n - 2; 0 <= i; i--) {
            if (r1 < arr[i]);
        }*/
    }
};