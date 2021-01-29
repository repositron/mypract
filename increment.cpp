//
// Created by ljw on 2/01/21.
//


#include <algorithm>
#include <iostream>
#include <functional>

#include "increment.h"

namespace increment {
    int incrementWithoutParam() {
        auto decrementFn = [](int* array, int size, int val) {
            for (int i = 0; i < size; i++) {
                array[i] = array[i] - val;
            }
        };


        int arr[] = {6, 7, 8, 9, 10};
        int n = sizeof(arr) / sizeof(arr[0]);

        auto decrement = std::bind(decrementFn, arr, n, std::placeholders::_1);
        //decrement one in each element arr


        decrement(1);
        //std::transform(arr, arr + n, arr, decrement(1));
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        //decrement two in each element arr
        decrement(2);
        //std::transform(arr, arr + n, arr, decrement(2));
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << "";
        return 1;
    }
}

