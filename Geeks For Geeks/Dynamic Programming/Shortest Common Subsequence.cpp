#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {

            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[x][y];
}

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    int a = lcs(m, n, X, Y);

    return m + n - a;
}