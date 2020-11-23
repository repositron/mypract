//
// Created by ljw on 21/11/20.
//

#include "CountRectangles.h"


namespace CountRectangles {
/*    struct {
        bool operator()(const Point& a, const Point& b) const
        {
            return a.x < b.x;
        }
    } custom;*/
    void sort(std::vector<Point>& points) {
        std::sort(points.begin(), points.end(),
                  [](const Point& a, const Point& b) {
                      if ( a.x != b.x )
                      {
                          return (a.x < b.x);
                      }
                      return (a.y < b.y);
                  });
    }

    int countRectangles(std::vector<Point>& points) {
        sort(points);
        int count = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            auto rectOrigin = points[i];
            std::vector<int> verticalPositions;
            int j = 0;
            for (j = i + 1; j < points.size(), rectOrigin.x == points[i + j].x; j++)
            {
                verticalPositions.push_back(points[i + j].y);
            }
            for (int k = 0; k < verticalPositions.size(); k++) {
                
            }

        }
        return 0;
    }
};