//
// Created by ljw on 30/08/20.
//

#ifndef MYPRACT_Q1_H
#define MYPRACT_Q1_H

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct Q1 {

    static int op(int a) {
        return ceil(a/2.0);
    }

    static int minSum(vector<int> num, int k) {
        for (int i = 0; i < k; i++) {
            int max = 0;
            for (int j = 1; j < num.size(); j++) {
                if (num.at(j) > num.at(max)) {
                    max = j;
                }
            }
            num[max] = op(num.at(max));
        }
        return accumulate(num.begin(), num.end(), 0);
    }



};


#endif //MYPRACT_Q1_H
