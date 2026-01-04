#include <stack>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)


void reverseStack(stack<int> &stack) 
{
    if(stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    stack<int> temp;
    while(!stack.empty())
    {
        temp.push(stack.top());
        stack.pop();
    }

    stack.push(num);

    while(!temp.empty())
    {
        stack.push(temp.top());
        temp.pop();
    }
}
