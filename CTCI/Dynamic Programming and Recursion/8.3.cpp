#include <bits/stdc++.h>
using namespace std;

//Question part 1
int solve(vector<int> arr, int l, int r)
{
    int res = -1;
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (arr[mid] == mid)
            return mid;

        if (arr[mid] < mid)
            l = mid + 1;
        else if (arr[mid] > mid)
            r = mid - 1;
    }

    return res;
}

//Question part 2
int solve(vector<int> arr, int l, int r)
{
    if (r < l)
        return -1;
    int a, b;

    int mid = l + ((r - l) / 2);

    if (arr[mid] == mid)
        return mid;

    a = solve(arr, l, min(arr[mid], mid - 1));
    if (a >= 0)
        return a;

    b = solve(arr, max(arr[mid], mid + 1), r);
    return b;
}