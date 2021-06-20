#include <bits/stdc++.h>
using namespace std;

//Recursive
int solve(int value)
{
    if (value == 0)
        return 1;
    if (value <= 0)
        return 0;

    int a, b, c;

    a = solve(value - 1);
    b = solve(value - 2);

    return (a + b) % 1000000007;
}

int countWays(int n)
{
    return (solve(n) % 1000000007);
}

//Using DP
int countWays(int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int j = 1; j <= n; j++)
    {
        if (j >= 2)
            dp[j] = (dp[j] + dp[j - 2] + dp[j - 1]) % 1000000007;
        else
            dp[j] = (dp[j] + dp[j - 1]) % 1000000007;
    }

    return dp[n];
}

//OR
int countWays(int n)
{
    int a = 1;
    int b = 1;
    int temp;

    for (int j = 2; j <= n; j++)
    {
        temp = (b + a) % 1000000007;
        b = a;
        a = temp;
    }

    return a;
}