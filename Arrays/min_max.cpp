// Problem: Find Min and Max
// Platform: Coding Ninjas
// Approach: Linear Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int,int> findMinMax(vector<int>& arr) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int x : arr) {
        mn = min(mn, x);
        mx = max(mx, x);
    }
    return {mn, mx};
}
