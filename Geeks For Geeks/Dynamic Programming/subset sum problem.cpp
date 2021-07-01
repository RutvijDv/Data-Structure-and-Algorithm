#include <bits/stdc++.h>
using namespace std;

//Brute force -> Recursive
bool solve(int a[], int i, int grp, int sum)
{
    if (i == 0)
    {
        if (grp * 2 == sum)
            return true;
        else
            return false;
    }

    return (solve(a, i - 1, grp - a[i - 1], sum) || solve(a, i - 1, grp, sum));
}

bool findPartition(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return solve(a, n, sum, sum);
}

//Dp Solution -> Memoisation

//Dp Solution -> Tabulation
bool findPartition(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum % 2 == 1)
        return false;
    bool dp[2][sum];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            if (j == 0)
                dp[i % 2][j] = true;

            else if (i == 0)
                dp[i % 2][j] = false;

            else if (j >= a[i - 1])
                dp[i % 2][j] = dp[(i + 1) % 2][j - a[i - 1]] || dp[(i + 1) % 2][j];
            else
                dp[i % 2][j] = dp[(i + 1) % 2][j];
        }
    }

    return dp[n % 2][sum / 2];
}