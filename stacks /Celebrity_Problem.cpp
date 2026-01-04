#include <vector>
#include <stack>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)



class Solution {
private:
    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();
        stack<int> s;

        for(int i = 0; i < n; i++)
            s.push(i);

        while(s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if(knows(mat, a, b))
                s.push(b);
            else
                s.push(a);
        }

        int ans = s.top();

        for(int i = 0; i < n; i++) {
            if(i != ans && mat[ans][i] == 1)
                return -1;
        }

        for(int i = 0; i < n; i++) {
            if(i != ans && mat[i][ans] == 0)
                return -1;
        }

        return ans;
    }
};
