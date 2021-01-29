//
// Created by ljw on 1/01/21.
//


/*
Good morning! Here's your coding interview problem for today.
This problem was asked by Slack.
You are given a string formed by concatenating several words corresponding to the integers zero through nine and then anagramming.
For example, the input could be 'niesevehrtfeev', which is an anagram of 'threefiveseven'. Note that there can be multiple instances of each integer.
Given this string, return the original integers in sorted order. In the example above, this would be 357.
*/
#include "NumStrings.h"
#include <unordered_map>
#include <map>
#include <vector>

namespace NumStrings {
    std::vector<std::string> numStrs = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::unordered_map<char, std::vector<std::string *>> charNumbMap;

    std::string unanagram(const std::string &anagram) {
        std::unordered_map<char, int> letterCount;
        for (const char &c: anagram) {
            letterCount[c]++;
        }

        while (!letterCount.empty()) {
            for (const auto &n: letterCount) {
                auto where = charNumbMap.find(n.first);
                if (where == charNumbMap.end()) {

                    for (const auto &i : numStrs) {

                    }
                }

            }
        }
        return std::string("");
    }
}
