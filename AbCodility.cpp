//
// Created by ljw on 14/06/21.
//

#include "AbCodility.h"
#include <vector>
//https://en.wikipedia.org/wiki/Negative_base
namespace AbCodility {
    using namespace std;
    int div2ceil(int val) {
        return val % 2 == 0 ? val / 2 : val / 2 + 1;
    }

    int calcValue(vector<int>& A) {
        int val = 0;
        int p = 1;
        for (std::size_t i = 0; i < A.size(); i++) {
            if (A[i] == 1) {
                if (i % 2 == 0)
                    val += p;
                else
                    val -= p;
            }
            p *= 2;
        }
        return val;
    }
    vector<int> solution(vector<int> &A) {
        if (A.empty())
            return {};
/*
        int summedValue = calcValue(A);
        int findVal = div2ceil(summedValue);
*/
        if (A.size() == 1) {
            return A;
        }

        bool carry = false;
        std::size_t r = A.size() - 1;
        for (; r > 0; r -= 2) {
            auto l = r - 1;
            if (A[l] == 1 && A[r] == 0) {
                if (carry) {
                    A[l] = 0;
                    carry = true;
                } else {
                    carry = true;
                }
            }
            else if (A[l] == 0 && A[r] == 1) {
                if (carry) {
                    A[l] = 1;
                    A[r] = 1;
                    carry = false;
                } else {
                    A[l] = 1;
                    A[r] = 0;
                    carry = false;
                }
            } else if (A[l] == 1 && A[r] == 1) {
                if (carry) {
                    A[l] = 1;
                    A[r] = 1;
                    carry = false;
                } else {
                    if (l > 0 && A[l - 1] == 1) {
                        A[l - 1] = 0;
                        A[l] = 1;
                        A[r] = 1;
                        carry = false;
                    } else {
                        A[l] = 0;
                        A[r] = 0;
                        carry = true;
                    }
                }
            } else {
                if (carry) {
                    A[r] = 1;
                    carry = false;
                }
            }
        }
        if (r == 0) {
            if (A[0] == 1) {
                if (carry) {
                    A[0] = 1;
                } else {
                    A[0] = 1;
                }
            }
            else {
                if (carry) {
                    A[0] = 1;
                }
            }
        }
        if (A[A.size() - 1] == 0)
            A.pop_back();
        if (A[A.size() - 1] == 0)
            A.pop_back();
        return A;
    }
};