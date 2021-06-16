#include <bits/stdc++.h>
using namespace std;
//Simple Approach ---> loop 1 to n and call decimal to binary

//Queue Approach
vector<string> generate(int N)
{
    vector<string> res;
    queue<string> q;

    q.push("1");

    while (N--)
    {
        string s = q.front();
        res.push_back(s);
        q.pop();

        q.push(s + "0");
        q.push(s + "1");
    }

    return res;
}