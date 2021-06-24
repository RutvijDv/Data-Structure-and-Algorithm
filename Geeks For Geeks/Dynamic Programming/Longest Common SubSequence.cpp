#include <bits/stdc++.h>
using namespace std;

//Naive Solution
int lcs(int x, int y, string s1, string s2)
{
    if (x == 0 || y == 0)
        return 0;

    if (s1[x - 1] == s2[y - 1])
        return 1 + lcs(x - 1, y - 1, s1, s2);

    else
        return max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
}

//Better Solution (Memoization)
int util(int x, int y, string s1, string s2, vector<vector<int>> &dp)
{
    if (dp[x][y] == -1)
    {
        if (x == 0 || y == 0)
            dp[x][y] = 0;

        else if (s1[x - 1] == s2[y - 1])
        {
            dp[x][y] = 1 + util(x - 1, y - 1, s1, s2, dp);
        }
        else
        {
            dp[x][y] = max(util(x, y - 1, s1, s2, dp), util(x - 1, y, s1, s2, dp));
        }
    }
    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
    util(x, y, s1, s2, dp);

    return dp[x][y];
}

//Efficient Solution (Tabulation)
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