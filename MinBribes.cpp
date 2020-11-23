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
            if (q[i] < q[ofIndex]) {
                count++;
                if (count > 2)
                    return count;
            }

        }
        return count;
    }

    int minimumBribes1(const vector<int>& q) {

        int count = 0;

        for (int i = q.size() - 1; 0 <= i; i--) {
            int val = q[i] - i  - 1;
            if (val > 2)
                return -1;
            for (int j = max(0, q[i] - 2);  j < i; j++) {
                if (q[i] < q[j])
                    count++;
            }
        }
        return count;
    }



    void minimumBribes(vector<int> q) {
        auto b = minimumBribes1(q);
        if (b == -1)
            cout << "Too chaotic\n";
        else
            std::cout << b << "\n";
    }

};