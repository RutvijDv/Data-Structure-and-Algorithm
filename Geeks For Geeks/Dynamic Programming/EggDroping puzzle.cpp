#include <bits/stdc++.h>
using namespace std;

//Brute Force
int eggDrop(int n, int k)
{
    if (n == 1)
        return k;
    if (k == 1 || k == 0)
        return k;

    int res = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        res = min(res, max(eggDrop(n - 1, i - 1), eggDrop(n, k - i)) + 1);
    }

    return res;
}

//DP Solution -> Memoisation
int solve(int n, int k, vector<vector<int>> &dp)
{
    if (n == 1)
        return k;
    if (k == 1 || k == 0)
        return k;

    if (dp[n][k] != 0)
        return dp[n][k];

    int res = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        res = min(res, max(eggDrop(n - 1, i - 1), eggDrop(n, k - i)) + 1);
    }

    dp[n][k] = res;

    return res;
}

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    int res = solve(n, k, dp);

    return res;
}

//DP Solution -> Tabulation
int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j <= k; j++)
    {
        dp[1][j] = j;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][x - 1], dp[i][j - x]) + 1);
            }
        }
    }

    return dp[n][k];
}
