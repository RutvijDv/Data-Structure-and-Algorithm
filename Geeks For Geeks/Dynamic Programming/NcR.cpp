#include <bits/stdc++.h>
using namespace std;

//Simple using Factor

//Using Recursion
int nCrModp(int n, int r)
{
    if (r > n)
        return 0;
    if (r == n || r == 0)
        return 1;

    int res = (nCrModp(n - 1, r) + nCrModp(n - 1, r - 1)) % 1000000007;

    return res;
}

//Using DP (Memoization)
int solve(int n, int r, vector<vector<int>> &dp)
{
    if (r > n)
        dp[n][r] = 0;
    if (r == n || r == 0)
        dp[n][r] = 1;

    if (dp[n][r] == -1)
    {
        dp[n][r] = (solve(n - 1, r, dp) + solve(n - 1, r - 1, dp)) % 1000000007;
    }

    return dp[n][r];
}

int nCrModp(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    solve(n, r, dp);

    return dp[n][r];
}

//Using DP (Tabulation)
int nCrModp(int n, int r)
{
    if (r > n)
        return 0;
    int dp[r + 1] = {-1};

    for (int i = 1; i <= n; i++)
    {
        for (int j = r; j >= 0; j--)
        {

            if (j == i || j == 0)
                dp[j] = 1;
            else
            {
                dp[j] = (dp[j] + dp[j - 1]) % 1000000007;
            }
        }
    }

    return dp[r];
}