// Problem: Second Largest Element
// Platform: Coding Ninjas
// Approach: Single Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {
    int largest = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        } else if (x > second && x != largest) {
            second = x;
        }
    }
    return (second == INT_MIN) ? -1 : second;
}
