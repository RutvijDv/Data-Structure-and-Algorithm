#include <bits/stdc++.h>
using namespace std;

//Using recursion
int solve(int value, int count)
{

    if (value == 0)
        return 1;
    if (count == 0)
        return 0;

    int a = 0, b;

    if (count <= value)
        a = solve(value - count, count);
    b = solve(value, count - 1);

    return (a + b) % 1000000007;
}

int countWays(int n)
{
    return ((solve(n, n) - 1) % 1000000007);
}

//Using DP
int countWays(int n)
{
    vector<long long int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
                dp[j] = (dp[j] + dp[j - i]) % (1000000007);
        }
    }

    return dp[n] % (1000000007);
}