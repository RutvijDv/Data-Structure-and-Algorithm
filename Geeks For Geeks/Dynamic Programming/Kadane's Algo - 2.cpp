#include <bits/stdc++.h>
using namespace std;

//Recursive Solution
long long solve(int arr[], int idx)
{
    if (idx == 0 || idx == 1)
        return arr[idx];
    long long res = arr[idx];

    for (int i = idx - 2; i >= 0; i--)
    {
        res = max(res, solve(arr, i) + arr[idx]);
    }

    return res;
}

long long maximumSum(int arr[], int n)
{
    long long ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, solve(arr, i));
        // cout<<ans<<endl;
    }

    return ans;
}

//Using DP - 1
long long maximumSum(int arr[], int n)
{
    long long temp;
    vector<long long> dp(n, INT_MIN);
    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        temp = max((long long)arr[i], dp[i - 2] + arr[i]);
        dp[i] = max(dp[i - 1], temp);
    }

    return dp[n - 1];
}
