
// Time Complexity: O(N)
// Space Complexity: O(K)     

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        deque<int> dq;
        vector<int> ans;
        int N = arr.size();

        // Process first window
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) {
                dq.push_back(i);
            }
        }

        // Store answer for first window

        if(!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);

        // Process remaining windows

        for(int i = k; i < N; i++) {

            // Remove out-of-window elements

            if(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // Add current element

            if(arr[i] < 0) {
                dq.push_back(i);
            }

            // Store answer

            if(!dq.empty())
                ans.push_back(arr[dq.front()]);
            else
                ans.push_back(0);
        }

        return ans;
    }
};
