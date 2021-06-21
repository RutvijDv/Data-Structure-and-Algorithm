#include <bits/stdc++.h>
using namespace std;

//Recursive
int solve(int value, int step)
{
    if (value == 0)
        return 1;
    if (step == 0)
        return 0;

    long long a = 0, b;

    if (step <= value)
        a = solve(value - step, step);
    b = solve(value, step - 1);

    return (a + b);
}

long long countWays(int n)
{
    return solve(n, 2);
}

//Using DP
long long countWays(int n)
{
    vector<long long int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
                dp[j] = (dp[j] + dp[j - i]);
        }
    }

    return dp[n];
}

//OR
long long countWays(int n)
{
    vector<long long int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int j = 2; j <= n; j++)
    {
        dp[j] = (dp[j - 2] + 1);
    }

    return dp[n];
}