//
// Created by ljw on 18/09/20.
//

#include "RansomNote.h"
#include <bits/stdc++.h>
#include <unordered_set>

namespace RansomNote {
    using namespace std;
    bool checkMagazine0(const vector<string>& magazine, const vector<string>& note) {
        unordered_multiset<string> words(magazine.begin(), magazine.end());
        for(const auto& n: note) {
            auto where = words.find(n);
            if (where == words.end())
                return false;
            else
                words.erase(where);

        }
        return true;
    }
    void checkMagazine(vector<string> magazine, vector<string> note) {
        cout << (checkMagazine0(magazine, note) ? "Yes" : "No");
    }
};