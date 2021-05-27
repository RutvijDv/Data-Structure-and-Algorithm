#include <bits/stdc++.h>
using namespace std;

void permute(string str, int n, int k, string &ans)
{
    if (str > ans)
        ans = str;
    if (k == 0)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[j] > str[i])
            {
                swap(str[i], str[j]);
                permute(str, n, k - 1, ans);
                swap(str[i], str[j]);
            }
        }
    }
}

string findMaximumNum(string str, int k)
{
    int n = str.length();
    string ans = "";
    permute(str, n, k, ans);
    return ans;
}