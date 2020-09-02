//
// Created by ljw on 22/08/20.
//

#ifndef MYPRACT_CHANGEMAKER_H
#define MYPRACT_CHANGEMAKER_H

#include <string>
#include <vector>

struct ChangeMaker {
    static std::string change(int price, int change);
    static std::vector<std::string> calc(int amount);
};


#endif //MYPRACT_CHANGEMAKER_H
