
// Time Complexity: O(N)
// Space Complexity: O(K)    


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        // step 1. pop first kth element fron queue and push into the stack
        
        stack<int> s;
        
        for(int i = 0; i<k; i++)
        {
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        
        // step 2. fetch kth element from stack and push into the queue
        
        while(!s.empty())
        {
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        
        // step 3. fetch fisrt n-k element fron queueand push it in the back
        
        int t = q.size() - k;
        
        while(t--)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};
