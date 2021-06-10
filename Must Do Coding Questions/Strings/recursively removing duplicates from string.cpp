#include <bits/stdc++.h>
using namespace std;

string solve(string &s)
{
    if (s.length() == 0)
    {
        return s;
    }

    int i = 0, n = s.length();
    string out;
    while (i < n)
    {
        if (s[i] == s[i + 1])
        {
            while (s[i] == s[i + 1])
                i++;
            i++;
        }
        else
        {
            out += s[i];
            i++;
        }
    }
    return out;
}

string remove(string s)
{

    string res = s;
    string temp;

    while (temp != res)
    {
        // cout<<res<<endl;
        temp = res;
        res = solve(res);
    }
    return res;
}