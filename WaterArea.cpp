//
// Created by ljw on 26/11/20.
//

#include "WaterArea.h"
namespace WaterArea {



    int waterAreaDp(std::vector<int> h) {
        int left[h.size()];
        left[0] = 0;
        for (int i = 1; i < h.size(); i++)
            left[i] = std::max(left[i - 1], h[i - 1]);
        int right[h.size()];

        right[h.size() - 1] = 0;
        for (int i = h.size() - 2; i >= 0; i--)
            right[i] = std::max(right[i + 1], h[i + 1]);

        int area = 0;
        for (int i = 0; i < h.size(); i++) {
            int height = std::min(left[i], right[i]);
            if (h[i] < height)
                area += (height - h[i]);
        }
        return area;
    }

    int waterArea(std::vector<int> h) {
        if (h.size() < 2)
            return 0;
        int l = 0;
        while (h[l] <= 0 && l < h.size() -1)
            l++;

        int r = l + 1;

        int answer = 0;
        while (r < h.size()) {
            if (h[l] < h[r]) {
                for (int i = l + 1; i < r; i++) {
                    answer += h[i];
                }
                l = r;
            }
        }
        /*
        int r = h.size() - 1;
        while (r > 0 && h[r] <=0)
            r--;

        if (r <= l)
            return 0;

        int height = std::min(h[r], h[l]);
        int maxArea =  height * (r - l -1);
        for (int i = l + 1;  i < r; i++) {
            if (h[i] <= height) {
                maxArea -= h[i];
            }
            else
                maxArea -= height;
        }*/
        return 0;
    }


}