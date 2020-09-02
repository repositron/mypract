//
// Created by ljw on 2/09/20.
//
#include <bits/stdc++.h>
#include "MinBribes.h"
namespace MinBribes {


    using namespace std;

    int ahead(const vector<int> &q, int ofIndex) {
        int count = 0;
        for (int i = ofIndex + 1; i < q.size(); i++) {
            if (q[i] < q[ofIndex])
                count++;
        }
        return count;

    }

    int minimumBribes0(const vector<int>& q) {
        int b = 0;
        for (int i = 0; i < q.size(); i++) {
            auto diff = ahead(q, i);
            //if (q[i] - 1 != i) {
            //auto diff  = q[i] - 1 - i;

            if (diff > 2) {

                return -1;
            }
            if (diff > 0)
                b += diff;
            //}
        }
        return b;
    }
    void minimumBribes(vector<int> q) {
        auto b = minimumBribes0(q);
        if (b == -1)
            cout << "Too chaotic\n";
        else
            std::cout << b << "\n";
    }

};