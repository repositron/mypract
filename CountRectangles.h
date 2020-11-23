//
// Created by ljw on 21/11/20.
//

#ifndef MYPRACT_COUNTRECTANGLES_H
#define MYPRACT_COUNTRECTANGLES_H


#include <vector>

namespace CountRectangles {

    struct Point {
        int x, y;
    };
    struct Rectangle {
        Point a, b, c, d;
    };
    void sort(std::vector<Point>& points);

    int countRectangles(std::vector<Point>& points);
};


#endif //MYPRACT_COUNTRECTANGLES_H
