#include <bits/stdc++.h>
using namespace std;

//Brute Force -> Recursive
int solve(int arr[], int idx, int n)
{

    if (idx >= n)
        return 0;

    int a = arr[idx] + solve(arr, idx + 2, n);
    int b = solve(arr, idx + 1, n);

    return max(a, b);
}

int FindMaxSum(int arr[], int n)
{
    int res = solve(arr, 0, n);
}

//Dp Solution -> Memoisation
int solve(int arr[], int idx, int n, vector<int> &dp)
{

    if (idx >= n)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int a, b;

    a = dp[idx + 2] == -1 ? solve(arr, idx + 2, n, dp) : dp[idx + 2];
    b = dp[idx + 1] == -1 ? solve(arr, idx + 1, n, dp) : dp[idx + 1];

    dp[idx] = max(a + arr[idx], b);
    return dp[idx];
}

int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n + 2, -1);
    int res = solve(arr, 0, n, dp);

    return res;
}

//Dp Solution -> Tabulation
int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n + 2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == (n - 1))
            dp[i] = arr[n - 1];
        else if (i == (n - 2))
            dp[i] = max(arr[n - 2], arr[n - 1]);
        else
        {
            dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
        }
    }

    return dp[0];
}