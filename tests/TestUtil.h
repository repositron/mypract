//
// Created by ljw on 5/09/20.
//

#ifndef MYPRACT_TESTUTIL_H
#define MYPRACT_TESTUTIL_H

#include <vector>
#include <string>

namespace TestUtil {
    using namespace std;
    vector<string> split_string(string input_string);
    vector<vector<int>> load(const string& path);
};


#endif //MYPRACT_TESTUTIL_H
