#include <bits/stdc++.h>
using namespace std;

//Simple Recursive
long long solve(int coins[], int n, int value)
{
    if (value == 0)
        return 0;
    if (n == 0)
        return 99999;

    long long int a = 99999, b;

    if (coins[n - 1] <= value)
        a = 1 + solve(coins, n, value - coins[n - 1]);
    b = solve(coins, n - 1, value);

    long long int res = min(a, b);
    return res;
}

long long minimumNumberOfCoins(int coins[], int n, int value)
{
    long long int res = solve(coins, n, value);

    if (res >= 99999)
        return -1;
    else
        return res;
}

//Using DP (Memoisation)
long long solve(int coins[], int n, int value, vector<vector<long long>> dp)
{

    if (dp[value][n] == -1)
    {

        if (value == 0)
            return 0;
        if (n == 0)
            return 99999;

        long long int a = 99999, b;

        if (coins[n - 1] <= value)
            a = 1 + solve(coins, n, value - coins[n - 1], dp);
        b = solve(coins, n - 1, value, dp);

        dp[value][n] = min(a, b);
    }

    return dp[value][n];
}

long long minimumNumberOfCoins(int coins[], int n, int value)
{
    vector<vector<long long>> dp(value + 1, vector<long long>(n + 1, -1));

    long long int res = solve(coins, n, value, dp);

    if (res >= 99999)
        return -1;
    else
        return res;
}

//Using DP (Tabulation)
long long minimumNumberOfCoins(int coins[], int n, int value)
{
    vector<long long> dp(value + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            if (j >= coins[i])
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
    }

    if (dp[value] == INT_MAX)
        return -1;
    else
        return dp[value];
}