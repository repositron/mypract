//
// Created by ljw on 16/09/21.
//

#ifndef MYPRACT_FINDIFPATHEXISTSGRAPH_H
#define MYPRACT_FINDIFPATHEXISTSGRAPH_H

#include <vector>

namespace FindIfPathExistsGraph {

    std::vector<std::vector<int>> generate(int n, const std::vector<std::tuple<int, int>> edges);

    bool validPath(int n, std::vector<std::vector<int>>& edges, int start, int end);
};


#endif //MYPRACT_FINDIFPATHEXISTSGRAPH_H
