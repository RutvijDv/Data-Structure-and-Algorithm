#include <bits/stdc++.h>
using namespace std;

void solve(string ans, int l, int r, vector<string> &res)
{
    if (l < 0 || r < 0)
        return;
    if (l == 0 && r == 0)
    {
        res.push_back(ans);
        return;
    }

    if (l == r)
    {
        solve(ans + "(", l - 1, r, res);
    }
    else
    {
        solve(ans + "(", l - 1, r, res);
        solve(ans + ")", l, r - 1, res);
    }

    return;
}

vector<string> AllParenthesis(int n)
{
    vector<string> res;
    solve("", n, n, res);
    return res;
}