//
// Created by ljw on 4/12/20.
//

#ifndef MYPRACT_STAIRCASE_H
#define MYPRACT_STAIRCASE_H


struct Staircase {

    static int c0(int n, int mem[]) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        else {
            if (mem[n] != 0)
                return mem[n];
            else
                return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }

    static int climbStairs(int n) {
        int* mem = new int[n];
        for (int i = 0; i < n; i++)
            mem[i] = 0;

        int answer = c0(n, mem);
        delete[] mem;
        return answer;

    }
};


#endif //MYPRACT_STAIRCASE_H
