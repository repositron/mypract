//
// Created by ljw on 21/11/20.
//

#include "CountRectangles.h"
#include <set>
#include <unordered_map>

namespace CountRectangles {
/*    struct {
        bool operator()(const Point& a, const Point& b) const
        {
            return a.x < b.x;
        }
    } custom;*/

    struct  PointCmp {
        bool operator()(const Point& a, const Point& b) const
        {
            if ( a.x != b.x )
            {
                return (a.x < b.x);
            }
            return (a.y < b.y);
        }
    };
    std::set<Point, PointCmp> getSet(const std::vector<Point>& points) {
        std::set<Point, PointCmp> pointsSet(points.begin(), points.end());
        return pointsSet;
    }
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


    int countRectangles(std::vector<Point>& pointsArr) {
        /*auto points = getSet(pointsArr);
        int count = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            auto rectOrigin = pointsArr[i];
            std::vector<int> verticalPositions;
            int j = 0;
            for (j = i + 1; j < points.size(), rectOrigin.x == points[i + j].x; j++)
            {
                verticalPositions.push_back(points.[i + j].y);
            }
            for (int k = 0; k < verticalPositions.size(); k++) {
                if (points.find({rectOrigin.x, rectOrigin.y}) != points.end()) {

                }
            }

        }*/
        return 0;
    }

    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    int countRectanglesFromYoutube(std::vector<Point>& pointsArr) {
        int answer = 0;
        std::unordered_map<std::pair<int, int>, int, pair_hash> count;
        for (Point p : pointsArr) {
            for (Point p_above: pointsArr) {
                if (p.x == p_above.x && p.y < p_above.y) {
                    std::pair<int, int> pair_y = std::make_pair(p.y, p_above.y);
                    answer += count[pair_y];
                    count[pair_y]++;
                }
            }
        }
        return answer;
    }
};