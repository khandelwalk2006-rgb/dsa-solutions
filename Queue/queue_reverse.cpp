
Time Complexity: O(N)
Space Complexity: O(N)


class Solution {
public:
    void reverseQueue(queue<int> &q) {
        stack<int> s;

        // Step 1: Queue → Stack
        while(!q.empty()) {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        // Step 2: Stack → Queue
        while(!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }
    }
};
