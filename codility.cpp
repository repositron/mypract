//
// Created by ljw on 26/01/21.
//


#include <unordered_set>
#include <string>
#include <sstream>

#include "codility.h"
namespace codility {

    using namespace std;

    std::unordered_set<int> prev;

    int s1(Tree* t, int count) {
        if (prev.contains(t->x))
            return 0;
        else {
            prev.insert(t->x);
        }

        count++;
        int lcount = 0;
        if (t->l != nullptr) {
            lcount = s1(t->l, count);
        }
        int rcount = 0;
        if (t->r != nullptr) {
            rcount = s1(t->r, count);
        }
        prev.erase(t->x);
        return max(lcount, rcount);
    }

    int solution(Tree* t) {
        return s1(t, 0);

    }

   /* std::string parseWord(std::stringstream& ss) {
        std::string s;
        char c = ss.get();
        if (ss.eof())
            return s;
        if (c == '(' || c == ')' || c == ',') {
            s.push_back(c);
            return s;
        }
        else if (isdigit(c)) {
            s.push_back(c);
            while ((c = ss.get()) && !ss.eof()) {
                s.push_back(c);
            }
            return s;
        }

    }*/

    int parseInt(std::istringstream& ss) {
        char c;
        std::string s;
        ss >> c;
        s.push_back(c);
        while ((c = ss.peek()) && !ss.eof() && std::isdigit(c)) {
            s.push_back(ss.get());
        }
        return std::stoi(s);
    }

    Tree* parseNode(std::istringstream& ss) {
        // assume '(' has been peeked
        char c = 0;
        ss >> c;
        if (ss.eof())
            return nullptr;
        if (c == '(') {
            Tree* t = new Tree;
            t->x = parseInt(ss);
            ss >> c; // ','
            // next could be ( or digit
            ss >> c;
            if (isdigit(c) && c == '0')
                t->l = nullptr;
            else {
                ss.putback(c);
                t->l = parseNode(ss);
            }
            ss >> c; // ','
            ss >> c;
            if (isdigit(c) && c == '0')
                t->r = nullptr;
            else {
                ss.putback(c);
                t->r = parseNode(ss);
            }
            ss >> c;
            return t;
        }
        return nullptr;
    }
    Tree* genTree(std::string& treeText) {
        // (2, 0, 0)
        // (2, (1, 0, 0), (2, 0, 0)

        auto ss = std::istringstream(treeText);
        ss.setf(std::ios::skipws);
        return parseNode(ss);
    }

    int solution2(vector<int>& S) {
        int max_sum = 0;
        int current_sum = 0;
        int positive = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            int item = S[i];
            if (item < 0) {
                if (max_sum < current_sum) {
                    max_sum = current_sum;
                    current_sum = 0;
                }
            } else {
                positive = 1;
                current_sum += item;
            }
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        if (positive) {
            return max_sum;
        }
        return -1;
    }


    int solution1(int A, int B) {
        // write your code in C++14 (g++ 6.2.0)
        auto aStr = std::to_string(A);
        auto bStr = std::to_string(B);
        auto where = bStr.find(aStr);
        if (where != std::string::npos) {
            return where;
        }
        else {
            return -1;
        }
    }
};