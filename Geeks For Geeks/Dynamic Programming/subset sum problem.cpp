#include <bits/stdc++.h>
using namespace std;

//Brute force -> Recursive
bool solve(int a[], int sum, int i, int n)
{
    if (sum == 0)
        return true;
    if (i == n)
        return false;

    int num = a[i];

    if (sum >= num)
        return (solve(a, sum - num, i + 1, n) || solve(a, sum, i + 1, n));
    else
        return solve(a, sum, i + 1, n);
}

bool findPartition(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % 2 == 1)
        return false;
    else
    {
        return solve(a, sum / 2, 0, n);
    }
}

//Dp Solution -> Memoisation

//Dp Solution -> Tabulation
bool findPartition(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % 2 == 1)
        return false;
    else
    {
        sum = sum / 2;
        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int num = a[i - 1];

                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (j >= num)
                    dp[i][j] = (dp[i - 1][j - num] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }
}

//OR

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