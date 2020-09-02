//
// Created by ljw on 30/08/20.
//

#ifndef MYPRACT_QX_H
#define MYPRACT_QX_H

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

extern vector<vector<int>> an;

struct QX {

    static void h0(vector<int> collection, vector<int> acc, int index, int d) {
        if (index >= collection.size()) {
            an.push_back(acc);
            return;
        }

        auto v1 = accumulate(acc.begin(), acc.end(), 0);

        h0(collection, acc, index + 1, d);
        acc.push_back(collection.at(index));
        h0(collection, acc, index + 1, d);




    }
    static vector<int> hackerCards(vector<int> collection, int d) {
        vector<int> acc;
        h0(collection, acc, 0, d);
        return acc;
    }
};


#endif //MYPRACT_QX_H
