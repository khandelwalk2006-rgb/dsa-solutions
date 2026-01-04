#include <stack>
using namespace std;

class SpecialStack {
    stack<int> s;
    int mini;

public:

    // Time Complexity: O(1)
    // Space Complexity: O(n)

    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if (data < mini) {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)

    int pop() {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();

        if (curr >= mini)
            return curr;
        else {
            int preMin = mini;
            mini = 2 * mini - curr;
            return preMin;
        }
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)

    int top() {
        if (s.empty())
            return -1;

        int curr = s.top();
        return (curr < mini) ? mini : curr;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)

    bool isEmpty() {
        return s.empty();
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int getMin() {
        if (s.empty())
            return -1;

        return mini;
    }
};
