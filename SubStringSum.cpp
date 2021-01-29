//
// Created by ljw on 23/01/21.
//

#include <cmath>
#include <vector>
#include <numeric>

#include "SubStringSum.h"

namespace SubStringSum {
    int substring1(const std::string& n) {
        int numDigits = n.length();
        uint64_t number = std::stoul(n);
        uint64_t divider = std::ceil(std::pow(10, numDigits));
        std::vector<uint64_t> subvalues;
        uint64_t total = 0;
        while (number) {
            for (uint64_t d = divider; 1 < d; d /= 10) {
                total += (number % d);
            }
            total %= 1000000007;
            number /= 10;
            divider /= 10;
        }
        return total;
    }
    int substrings(std::string n) {
        const int bundleSize = 5;
        int numDigits = n.length();
        uint64_t total = 0;
        for (int i = 0; i < numDigits; i += bundleSize) {
            int s = bundleSize <= (numDigits - i) ? bundleSize : numDigits - i;
            auto part = n.substr(i, s);
            total += substring1(part);
            total %= 1000000007;
        }
        return total;
    }

};