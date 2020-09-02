//
// Created by ljw on 22/08/20.
//

#include <map>
#include <array>
#include "ChangeMaker.h"
#include "ParserUtil.h"


std::vector<std::string> ChangeMaker::calc(int amount) {
    std::vector<std::string> change;
    const std::array<std::pair<std::string, int>, 12> table{
        std::pair{"ONE HUNDRED", 10000},
        std::pair{"FIFTY", 5000},
        std::pair{"TWENTY", 2000},
        std::pair{"TEN", 1000},
        std::pair{"FIVE", 500},
        std::pair{"TWO", 200},
        std::pair{"ONE", 100},
        std::pair{"HALF DOLLAR", 50},
        std::pair{"QUARTER", 25},
        std::pair{"DIME", 10},
        std::pair{"NICKEL", 5},
        std::pair{"PENNY", 1}};

    auto help = [&change](const std::string& v) {
        change.push_back(v);

    };
    int i = 0;
    while (0 < amount) {
        if (table[i].second <= amount) {
            change.push_back(table[i].first);
            amount -= table[i].second;
        }
        else
            i++;
    }
    return change;
}

std::string ChangeMaker::change(int price, int change) {
    if (change < price)
        return "ERROR";
    else if (change == price)
        return "ZERO";
    else
        return ParserUtil::makeStr(calc(change - price), ',');
}