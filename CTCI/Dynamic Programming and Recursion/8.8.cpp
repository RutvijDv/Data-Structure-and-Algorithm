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

//Approach 2
void permute(string s, vector<string> &res, unordered_map<char, int> mp, string ans)
{
    if (ans.length() == s.length())
    {
        res.push_back(ans);
        return;
    }
    for (auto i : mp)
    {
        if (i.second == 0)
            continue;
        char x = i.first;

        mp[x]--;
        permute(s, res, mp, ans + x);
        mp[x]++;
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;
    unordered_map<char, int> mp;

    for (int i = 0; i < S.length(); i++)
    {
        mp[S[i]]++;
    }

    permute(S, res, mp, "");

    sort(res.begin(), res.end());

    return res;
}