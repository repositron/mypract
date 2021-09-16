//
// Created by ljw on 27/08/21.
//

#include <vector>
#include <iterator>
#include <iostream>

namespace RemoveDuplicates {
    using namespace std;

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++ ) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }

    int removeDuplicatesx(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int previous = nums[0];
        size_t k = nums.size();
        vector<int>::iterator newEnd = nums.end();
        for (auto it = next(nums.begin()); it < newEnd;) {
            auto destIt = it;
            while (it < newEnd && *it == previous) {
                it++;
                //= prev(newEnd);
                k--;
            }
            // at this point it will be different from previous
            if (destIt < it) {
                copy(it, newEnd, destIt);
                newEnd = next(nums.begin(), k);
                it = destIt;
            }
            if (it < newEnd) {
                previous = *it;
                it++;
            }
        }
        return k;
    }
}
