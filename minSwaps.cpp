//
// Created by ljw on 31/08/20.
//

#include "minSwaps.h"

namespace minSwaps {

    void print(vector<int> arr) {
        int i;
        for (i = 0; i < arr.size() -1; i++)
            std::cout << arr.at(i) << ", ";
        std::cout << arr.at(i) << "\n";
    }

    int minimumSwaps(vector<int> arr) {
        cout << "arr:\t"; print(arr);
        vector<int> indexArr(arr.size());
        for (int i = 0; i <  arr.size(); i++)
            indexArr.at(arr.at(i) - 1) = i;
        cout << "index:\t"; print(indexArr);
        int swapCount = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != i + 1) {
                auto j = indexArr.at(i);
                cout << "swapping " << i << ", " << j << "\n";
                swap(arr[i], arr[j]);
                cout << "arr:\t"; print(arr);
                swap(indexArr[arr[i] - 1], indexArr[arr[j]- 1]);

               // for (int k = 0; k < arr.size(); k++)
                //    indexArr.at(arr.at(k) - 1) = k;
                cout << "index:\t"; print(indexArr);
                swapCount++;
            }
        }
        return swapCount++;
    }

};