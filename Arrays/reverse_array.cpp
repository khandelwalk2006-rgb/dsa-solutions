// Problem: Reverse Array
// Platform: Coding Ninjas
// Approach: Two Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}
