#include <bits/stdc++.h>
using namespace std;

//Recursive
int getMin(int arr[], int n, int idx)
{

    int x = arr[idx], res = INT_MAX;

    if (x + idx >= n)
        return 1;

    for (int i = 1; i <= x; i++)
    {
        res = min(res, 1 + getMin(arr, n, idx + i));
    }

    return res;
}

int minimumJumps(int arr[], int n)
{

    int res = getMin(arr, n, 0);
    if (res >= INT_MAX)
        return -1;
    else
        return res;
}

//Using DP
