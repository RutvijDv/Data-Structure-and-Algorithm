#include <bits/stdc++.h>
using namespace std;

//Simple Solution ---> Use array or Stack DataStructure O(n) space and O(n) time

//But if we are restricted to use any other dataStructure we would use Recursion with same O(n) space and O(n) time

void deleteUtil(stack<int> &s, int k)
{
    if (k == 0)
    {
        s.pop();
        return;
    }
    int ele = s.top();
    s.pop();
    k--;
    deleteUtil(s, k);
    s.push(ele);
    return;
}

void deleteMid(stack<int> &s, int sizeOfStack)
{
    deleteUtil(s, sizeOfStack / 2);
    return;
}