#include <bits/stdc++.h>
using namespace std;

//Use 2 extra stacks ---> 1 original 1 buffer 1 final

//Use 1 extra stacks
void sort(stack<int> s)
{
    stack<int> temp;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        while (!temp.empty() && temp.top() < x)
        {
            int y = temp.top();
            temp.pop();
            s.push(y);
        }

        temp.push(x);
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    return;
}