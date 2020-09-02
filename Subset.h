//
// Created by ljw on 28/08/20.
//

#ifndef MYPRACT_SUBSET_H
#define MYPRACT_SUBSET_H

#include <vector>
#include <functional>
struct Subset {
private:
    static std::vector<std::vector<int>> subset0(std::vector<int>::iterator start, std::vector<int>::iterator end) {
        if (start == end) {
            return std::vector<std::vector<int>>({{}});
        }
        auto l1 = subset0(std::next(start), end);
        for (auto i: l1) {
            std::cout << *start << "\n";
            i.push_back(*start);
        }
        return l1;
    };

    static void subsetv2(std::vector<std::vector<int>>& accum, std::vector<int>::iterator start, std::vector<int>::iterator end) {
        if (start == end) {
            return;
        }
        else {
            for (auto i = start; i != end; i++) {
                accum.push_back(std::vector<int>({*i}));
                subsetv2(accum, std::next(start), end);
            }
        }
        return;
    }
public:
    static std::vector<std::vector<int>> subset(std::vector<int>& sourceValues) {

   /*     std::function<std::vector<std::vector<int>>(std::vector<int>::iterator&)> fn = [&](std::vector<int>::iterator& a){
            auto l1 = fn(std::next(a));
            for (auto i: l1) {

            }
            return l1;
        };*/
        std::vector<std::vector<int>> sset;
        subsetv2(sset, sourceValues.begin(), sourceValues.end());
        return sset;
    }

    static void subsetStr0(std::vector<std::string>& acc, std::string sofar, std::string values, int index) {
        if (values.size() <= index)
            acc.push_back(sofar);
        else {
            subsetStr0(acc, sofar + values[index], values, index + 1);
            subsetStr0(acc, sofar, values, index + 1);
        }
        /*for (auto i = index; i < values.size(); i++) {
            std::string str(1, values[i]);
            acc.push_back(str);
            subsetStr0(acc, values, index + 1);
        }*/
    }

    static std::vector<std::string> subsetStr(const std::string& sourceValues) {

        std::vector<std::string> acc;
        subsetStr0(acc, "", sourceValues, 0);
        return acc;
    }

};

#endif //MYPRACT_SUBSET_H
