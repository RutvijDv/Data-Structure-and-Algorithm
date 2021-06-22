#include <bits/stdc++.h>
using namespace std;

//Recursive - O(n^N)
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

//Using DP - O(n^2)
int minimumJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    vector<int> jumps(n, -1);
    jumps[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((i <= (j + arr[j])) && (jumps[j] != -1))
            {
                jumps[i] = jumps[j] + 1;
                break;
            }
        }
        // cout<<jumps[i]<<endl;
    }
    return jumps[n - 1];
}

//Using Tactics - O(n)
int minimumJumps(int arr[], int n)
{

    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int range = arr[0];
    int jumps = 1;
    int steps = arr[0];
    int curr = 1;

    if (range >= (n - 1))
        return jumps;

    while (steps && curr < n)
    {

        if (curr == (n - 1))
            return jumps;

        range = max(range, arr[curr] + curr);

        steps--;

        if (steps == 0)
        {
            if (range <= curr)
                return -1;
            steps = range - curr;
            jumps++;
        }

        curr++;
    }

    return -1;
}