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
