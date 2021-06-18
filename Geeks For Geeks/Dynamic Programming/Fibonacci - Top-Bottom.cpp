#include <bits/stdc++.h>
using namespace std;

long long findNthFibonacci(int n, long long int dp[])
{
    if (dp[n] == 0)
    {

        dp[n] = findNthFibonacci(n - 1, dp) + findNthFibonacci(n - 2, dp);
    }
    return dp[n];
}