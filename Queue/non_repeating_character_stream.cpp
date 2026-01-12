
// Time Complexity: O(N)
// Space Complexity: O(1)      


class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // increase count

            count[ch]++;
            
            // push to queue
            q.push(ch);
            
            // remove repeating chars from queue front
            while(!q.empty() && count[q.front()] > 1) {
                q.pop();
            }
            
            // check queue front for answer

            if(q.empty())
            {
                ans.push_back('#');
            }
            else
            {
                ans.push_back(q.front());
            }
        }
        
        return ans;
    }
};
