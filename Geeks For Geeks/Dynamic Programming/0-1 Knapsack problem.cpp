#include <bits/stdc++.h>
using namespace std;

//Brute force -> Recursive
int solve(int W, int wt[], int val[], int n, int i)
{
    if (i == 0 || W == 0)
        return 0;

    int a = 0, b = 0;

    if (W >= wt[i])
        a = val[i] + solve(W - wt[i], wt, val, n, i - 1);
    b = solve(W, wt, val, n, i - 1);

    return max(a, b);
}

int knapSack(int W, int wt[], int val[], int n)
{
    int res;
    res = solve(W, wt, val, n, n - 1);
    return res;
}

//Dp Solution Memoisation
int solve(int W, int wt[], int val[], int n, int i, vector<vector<int>> &dp)
{
    if (dp[i][W] != -1)
        return dp[i][W];
    if (i == 0 || W == 0)
        return 0;

    int a = 0, b = 0;

    if (W >= wt[i - 1])
        a = dp[i - 1][W - wt[i - 1]] == -1 ? val[i - 1] + solve(W - wt[i - 1], wt, val, n, i - 1, dp) : val[i - 1] + dp[i - 1][W - wt[i - 1]];
    b = dp[i - 1][W] == -1 ? solve(W, wt, val, n, i - 1, dp) : dp[i - 1][W];

    dp[i][W] = max(a, b);
    return dp[i][W];
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int res;
    res = solve(W, wt, val, n, n, dp);
    return res;
}
//Dp Solution Tabulation
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= wt[i - 1])
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}