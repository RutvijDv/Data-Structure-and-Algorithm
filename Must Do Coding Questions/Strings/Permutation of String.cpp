#include <bits/stdc++.h>
using namespace std;

//Backtracking Solution
void permute(string s, int i, vector<string> &res)
{

    if (i == s.length() - 1)
    {
        res.push_back(s);
        return;
    }

    for (int j = i; j <= s.length() - 1; j++)
    {
        swap(s[j], s[i]);
        permute(s, i + 1, res);
        swap(s[j], s[i]);
    }

    return;
}

vector<string> find_permutation(string S)
{
    vector<string> res;

    permute(S, 0, res);

    sort(res.begin(), res.end());

    return res;
}

//Another approach
void permute(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << "  ";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch);
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;

    permute(S, 0, res);

    sort(res.begin(), res.end());

    return res;
}