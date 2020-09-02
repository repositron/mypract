//
// Created by ljw on 23/08/20.
//

#ifndef MYPRACT_PARSERUTIL_H
#define MYPRACT_PARSERUTIL_H

#include <sstream>
#include <tuple>
#include <vector>

struct ParserUtil {
    static std::tuple<int, int> convertDoublePair(const std::string& s) {
        std::istringstream iss{s};
        std::string token;
        double a, b;
        //std::getline(iss, token, ',');
        iss >> std::skipws >> a;
        char commar = ' ';
        iss >> std::skipws >> commar;
        iss >> std::skipws >> b;


        return std::make_tuple(a*100, b*100);
    }

    static std::string makeStr(std::vector<std::string> vs, char seperator) {
        auto i = vs.cbegin();
        std::string str;
        for (; i != std::prev(vs.cend()); i++) {
            str = str +  *i + seperator;
        }
        str += *i;
        return str;
    }
};


#endif //MYPRACT_PARSERUTIL_H
