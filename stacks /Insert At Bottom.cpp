
#include <stack>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)


void insertAtBottom(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(top);
}


#include <iostream>
void printStack(stack<int> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
