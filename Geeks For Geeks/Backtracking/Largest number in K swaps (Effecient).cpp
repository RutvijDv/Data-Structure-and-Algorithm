#include <bits/stdc++.h>
using namespace std;

void permute(string str, int n, int k, string &ans, int curr)
{
    if (str > ans)
        ans = str;
    if (k == 0)
        return;

    char maxi = str[curr];
    for (int i = curr + 1; i < n; i++)
    {
        if (str[i] > maxi)
            maxi = str[i];
    }

    if (maxi != str[curr])
        k--;

    for (int i = curr; i < n; i++)
    {
        if (str[i] == maxi)
        {
            swap(str[i], str[curr]);
            permute(str, n, k, ans, curr + 1);
            swap(str[i], str[curr]);
        }
    }
    return;
}

string findMaximumNum(string str, int k)
{
    int n = str.length();
    string ans = "";
    permute(str, n, k, ans, 0);
    return ans;
}