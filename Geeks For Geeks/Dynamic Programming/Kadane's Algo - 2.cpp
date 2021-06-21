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