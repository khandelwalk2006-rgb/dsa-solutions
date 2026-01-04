#include <stack>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)


bool isValidParenthesis(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // opening bracket
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // closing bracket
            if(!st.empty())
            {
                char top = st.top();

                if( (ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[') )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}
