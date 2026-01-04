// Problem: Check if Array is Sorted
// Platform: Coding Ninjas
// Approach: Linear Check
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
