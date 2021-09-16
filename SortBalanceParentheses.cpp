//
// Created by ljw on 16/09/21.
//

#include "SortBalanceParentheses.h"

namespace SortBalanceParentheses {
    std::string balanceSort(const std::string& input) {
        int bl=0, br=0;
        int pl=0, pr=0;
        auto norm = [&](int& a, int& b) {
            (a < b) ? b = a : a = b;
        };

        for (const auto& i : input) {
            if (i == '(')
                pl++;
            else if (i == ')')
                pr++;
            else if (i == '{')
                bl++;
            else
                br++;
        }
        norm(bl, br);
        norm(pl, pr);
        std::string answer;
        while (bl-- > 0)
            answer.push_back('(');
        while (pl-- > 0)
            answer.push_back('{');
        while (pr-- > 0)
            answer.push_back('}');
        while (br-- > 0)
            answer.push_back(')');

        return answer;
    }
}