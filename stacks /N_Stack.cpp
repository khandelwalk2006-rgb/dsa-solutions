#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:

 // Time Complexity: O(1) per push/pop
  // Space Complexity: O(s + n)

    NStack(int N, int S) {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i = 0; i < n; i++)
            top[i] = -1;

        for(int i = 0; i < s; i++)
            next[i] = i + 1;

        next[s - 1] = -1;
        freespot = 0;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)


    bool push(int x, int m) {
        if(freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];

        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)


    int pop(int m) {
        if(top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
