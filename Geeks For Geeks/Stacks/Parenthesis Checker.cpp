#include <bits/stdc++.h>
using namespace std;

bool cmp(char b, char c)
{
    if (b == '{' && c == '}')
        return true;
    else if (b == '[' && c == ']')
        return true;
    else if (b == '(' && c == ')')
        return true;
    return false;
}

bool ispar(string s)
{
    int n = s.length();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || !cmp(st.top(), s[i]))
                return false;
            st.pop();
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}