//
// Created by ljw on 4/10/20.
//

#include "Rotate.h"
#include <bits/stdc++.h>

namespace Rotate {


    using namespace std;

    vector<int> rotLeft(vector<int> a, int d) {
        int size = a.size();
        int r = d % a.size();
        if (size == r)
            return a;
        int tmp[r];
        std::copy(a.begin(), a.end() - (size - r), &tmp[0]);
        std::copy(a.begin() + r, a.end(), a.begin());
        std::copy(&tmp[0], &tmp[r], a.begin() + (size - r));
        return a;

    }
};