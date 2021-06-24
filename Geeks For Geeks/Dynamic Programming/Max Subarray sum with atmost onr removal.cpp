#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n)
{
    int res;

    vector<int> forward(n, 0);
    vector<int> backward(n, 0);

    int maxi = arr[0];
    int maxEnd = arr[0];
    forward[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnd = max(arr[i], maxEnd + arr[i]);
        maxi = max(maxi, maxEnd);
        forward[i] = maxEnd;
    }

    maxi = arr[n - 1];
    maxEnd = arr[n - 1];
    backward[n - 1] = arr[n - 1];

    for (int i = (n - 2); i >= 0; i--)
    {
        maxEnd = max(arr[i], maxEnd + arr[i]);
        maxi = max(maxi, maxEnd);
        backward[i] = maxEnd;
    }

    res = maxi;

    for (int i = 1; i < n - 1; i++)
    {
        res = max(res, forward[i - 1] + backward[i + 1]);
    }

    return res;
}