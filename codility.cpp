//
// Created by ljw on 26/01/21.
//


#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>

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
        return std::max(lcount, rcount) + count;
    }

    int solution(Tree* t) {
        return s1(t, 0);

    }


    int calcMaxHeight(Tree* t) {
        int lheight = 0;
        if (t->l != nullptr) {
            lheight = calcMaxHeight(t);
        }

        int rheight = 0;
        if (t->r != nullptr) {
            rheight = calcMaxHeight(t);
        }

        return std::max(lheight, rheight) + 1;
    }

    void printNode(Tree* t, int rowWidth, int rowPos) {


    }

    std::string printTree(Tree* t) {
        int maxLength = calcMaxHeight(t);
        int width = 2 << (maxLength - 1);
        std::ostringstream ss;
        ss << "max length: " << maxLength << "; width: " << width << '\n';
        std::queue<Tree*> queue1;
        std::queue<Tree*> queue2;
       // auto& row1Nodes = queue1;
        //auto& row2Nodes = queue2;

        queue1.push(t);
        while (!queue1.empty()) {
            int rowWidth = queue1.size();
            int rowPos = 0;
            while (!queue1.empty()) {
                auto t = queue1.front();
                queue1.pop();
                printNode(t, rowWidth, rowPos++);

                if (t->l != nullptr)
                    queue2.push(t->l);
                if (t->r != nullptr)
                    queue2.push(t->r);

            }
            queue1.swap(queue2);
        }
        return ss.str();
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
            if (c != ')')
                throw std::runtime_error("expect )");
            return t;
        }
        else
            throw std::runtime_error("expect (");
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