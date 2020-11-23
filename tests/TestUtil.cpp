//
// Created by ljw on 5/09/20.
//

#include "TestUtil.h"
#include <bits/stdc++.h>

namespace TestUtil {
using namespace std;

vector<vector<int>> load(const string& path)
{
    ifstream f(path);
    if (!f)
        return {};

    int numberOfTests = 0;
    f >> numberOfTests;
    vector<vector<int>> tests;

    for (auto j = 0; j < numberOfTests; j++) {
        int n;
        f >> n;
        f.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(f, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }
        tests.push_back(arr);
    }
    return tests;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

};