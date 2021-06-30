#include <bits/stdc++.h>
using namespace std;

//Brute Force Recursive
long long solve(int arr[], int i, int j)
{
    if (i > j)
        return 0;
    long long x, y;

    if (i == j)
        return arr[i];

    x = arr[i] + min(solve(arr, i + 2, j), solve(arr, i + 1, j - 1));
    y = arr[j] + min(solve(arr, i + 1, j - 1), solve(arr, i, j - 2));

    return max(x, y);
}

long long maximumAmount(int arr[], int n)
{
    int i = 0, j = n - 1;
    long long res;

    res = solve(arr, i, j);

    return res;
}

//DP solution -> Memoisation
long long solve(int arr[], int i, int j, vector<vector<long long>> &res)
{
    if (i > j)
        return 0;

    if (res[i][j] != -1)
        return res[i][j];

    long long x, y;

    if (i == j)
        return arr[i];

    x = arr[i] + min(solve(arr, i + 2, j, res), solve(arr, i + 1, j - 1, res));
    y = arr[j] + min(solve(arr, i + 1, j - 1, res), solve(arr, i, j - 2, res));

    res[i][j] = max(x, y);

    return res[i][j];
}

long long maximumAmount(int arr[], int n)
{
    int i = 0, j = n - 1;
    long long out;
    vector<vector<long long>> res(n + 1, vector<long long>(n + 1, -1));

    out = solve(arr, i, j, res);

    return out;
}

//DP solution -> Tabulation
long long maximumAmount(int arr[], int n)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));

    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = arr[i];
            }
            else
            {
                long long x = dp[i + 2][j] == -1 ? 0 : dp[i + 2][j];
                long long y = dp[i + 1][j - 1] == -1 ? 0 : dp[i + 1][j - 1];
                long long z = dp[i][j - 2] == -1 ? 0 : dp[i][j - 2];

                dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }
    }

    return dp[0][n - 1];
}
