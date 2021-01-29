//
// Created by ljw on 14/01/21.
//

#include <unordered_map>
#include <iostream>
#include <vector>

#include "AbbreviationProblem.h"


namespace AbbreviationProblem {
    using Key = std::pair<std::string, std::string>;
    struct KeyHash {
        std::size_t operator()(const Key& k) const
        {
            return std::hash<std::string>()(k.first) ^
                   (std::hash<std::string>()(k.second) << 1);
        }
    };
    struct KeyEqual {
        bool operator()(const Key& lhs, const Key& rhs) const
        {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    };
    std::unordered_map<Key, bool, KeyHash, KeyEqual> mem;

    bool abbreviation1(const std::string& a, const std::string& b) {
        if (a.length() == 0 && b.length() == 0)
            return true;
        if (b.length() == 0) {
            for (auto c: a) {
                if (std::isupper(c))
                    return false;
            }
            return true;
        }
        if (a.length() < b.length())
            return false;
        auto where = mem.find(std::make_pair(a, b));
        if (where != mem.end()) {
            //std::cout << "*" << '\n';
            return mem[std::make_pair(a, b)];
        }

        if (std::isupper(a[0])) {
            if ((a[0] == b[0])) {
                auto result = abbreviation1(a.substr(1), b.substr(1));
                mem.insert(std::make_pair(std::make_pair(a.substr(1), b.substr(1)),
                                          result));
                return result;
            }
            else {
                return false;
            }
        }
        // a[0] is lower case so deletable
        auto aUp = std::toupper(static_cast<unsigned char>(a[0]));
        if (aUp != b[0]) {
            auto result = abbreviation1(a.substr(1), b); // de
            mem.insert(std::make_pair(std::make_pair(a.substr(1), b), result));
            return result;
        }
        else {
            auto r1 = abbreviation1(a.substr(1), b.substr(1));
            mem.insert(std::make_pair(std::make_pair(a.substr(1), b.substr(1)), r1));

            auto r2 = abbreviation1(a.substr(1), b);
            mem.insert(std::make_pair(std::make_pair(a.substr(1), b), r2));
            return (r1 || r2);
        }
    }

    template <typename T>
    class Vec2d {
    public:
        Vec2d(uint16_t x, uint16_t y)
            : v(x * y, 0) , xMax(x) {

        }
        const T& access(uint16_t x, uint16_t y) const {
            return v[xMax * y + x];
        }

        T& access (uint16_t x, uint16_t y) {
            return v[xMax * y + x];
        }
        std::vector<T> v;
        uint16_t xMax = 0;
    };
    struct Abbreviate2{
        Abbreviate2(const std::string& a, const std::string& b)
            : dp(a.size() + 1, b.size() + 1) , a(a), b(b) {
        }

        bool abbreviate() {
            dp.access(0, 0) = 1;
            for (int i = 0; i < a.length(); i++) {
                for (int j = 0; j <= b.length(); j++) {

                    if (dp.access(i, j) == 1) {

                        if (j < b.length() && (std::toupper(a[i]) == b[j]))
                            dp.access(i + 1, j + 1) = 1;

                        if (!std::isupper(a[i]))
                            dp.access(i + 1, j) = 1;
                    }
                }
            }

            return dp.access(a.size(), b.size());
        }

        Vec2d<u_int8_t> dp;
        std::string a;
        std::string b;

    };
    bool abbreviation2(const std::string& a, const std::string& b) {
        std::vector<std::vector<bool>> dp(a.size());
        for (auto i: dp)
            i.resize(b.size());
        return false;

    }

    std::string abbreviation(std::string a, std::string b) {
        Abbreviate2 abbr(a, b);
        return abbr.abbreviate() == 1 ? "YES" : "NO";
        //return abbreviation2(a, b) ? "YES" : "NO";
    }
};