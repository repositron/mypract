//
// Created by ljw on 11/12/20.
//

#include "Graph.h"
#include <fstream>
#include <stdexcept>

namespace graphUtil {

std::unique_ptr<Graph> read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file || file.bad())
        throw std::runtime_error("couldnt load " + filename);
    int v = 0, e = 0;
    file >> v;
    file >> e;
    auto graph = std::make_unique<Graph>(v);
    while (file.good() && e-- > 0) {
        int v1, v2;
        file >> v1;
        file >> v2;
        graph->addEdge(v1, v2);
    }
    return graph;
}

};