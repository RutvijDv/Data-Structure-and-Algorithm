#include <bits/stdc++.h>
using namespace std;

//Approach 1
void permute(string s, string answer, vector<string> &res)
{
    if (s.length() == 0)
    {
        res.push_back(answer);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch, res);
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;

    permute(S, "", res);

    sort(res.begin(), res.end());

    return res;
}

//Approach 1
void permute(string s, int l, vector<string> &res)
{
    if (s.length() == l)
    {
        res.push_back(s);
        return;
    }
    for (int i = l; i < s.length(); i++)
    {
        swap(s[l], s[i]);
        permute(s, l + 1, res);
        swap(s[l], s[i]);
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;

    permute(S, 0, res);

    sort(res.begin(), res.end());

    return res;
}
