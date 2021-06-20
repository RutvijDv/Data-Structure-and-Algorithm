#include <bits/stdc++.h>
using namespace std;

//Recusive Simple
long long solve(int coins[], int n, int value)
{
    if (value == 0)
        return 1;
    if (n == 0)
        return 0;

    long long int a = 0, b;

    if (coins[n - 1] <= value)
        a = solve(coins, n, value - coins[n - 1]);
    b = solve(coins, n - 1, value);

    long long int res = a + b;
    return res;
}

long long numberOfWays(int coins[], int n, int value)
{
    long long int res = solve(coins, n, value);

    return res;
}

//Using DP
long long numberOfWays(int coins[], int n, int value)
{
    vector<long long> dp(value + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            if (j >= coins[i])
                dp[j] = dp[j - coins[i]] + dp[j];
        }
    }

    return dp[value];
}