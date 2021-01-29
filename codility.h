//
// Created by ljw on 26/01/21.
//

#ifndef MYPRACT_CODILITY_H
#define MYPRACT_CODILITY_H

#include <string>
#include <vector>

namespace codility {

    struct Tree {
        int x = 0;
        Tree* l = nullptr;
        Tree* r = nullptr;
    };
    
    int solution(Tree*);
    Tree* genTree(std::string& treeText);
    int solution2(std::vector<int>& S);
    int solution1(int A, int B) ;
};


#endif //MYPRACT_CODILITY_H
