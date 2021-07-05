#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, vector<string> &res)
{
    unordered_map<char, bool> mp;
    if (s.length() == l)
    {
        res.push_back(s);
        return;
    }
    for (int i = l; i < s.length(); i++)
    {
        if (mp[s[i]] == true)
            continue;
        swap(s[l], s[i]);
        permute(s, l + 1, res);
        swap(s[l], s[i]);
        mp[s[i]] = true;
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;

    permute(S, 0, res);

    sort(res.begin(), res.end());

    return res;
}