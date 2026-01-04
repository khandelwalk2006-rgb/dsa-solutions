// Problem: Move Zeros to End
// Platform: Coding Ninjas
// Approach: Two Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr) {
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
