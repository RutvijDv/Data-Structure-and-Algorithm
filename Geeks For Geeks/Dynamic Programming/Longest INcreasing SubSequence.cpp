#include <bits/stdc++.h>
using namespace std;

//Naive approach -> Get all subsequences and check

//Better Solution -> keep track of LIS ending with every element
int longestSubsequence(int n, int a[])
{
    vector<int> lis(n, 1);
    int res = INT_MIN;

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        res = max(res, lis[i]);
    }

    return res;
}

//Efficient
int ceilIdx(int tail[], int l, int r, int key)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m + 1;
    }

    return r;
}

int longestSubsequence(int n, int a[])
{
    int tail[n] = {0};
    int l = 1;

    tail[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        if (tail[l - 1] < a[i])
        {
            tail[l] = a[i];
            l++;
        }
        else
        {
            int idx = ceilIdx(tail, 0, l - 1, a[i]);
            tail[idx] = a[i];
        }
    }

    return l;
}