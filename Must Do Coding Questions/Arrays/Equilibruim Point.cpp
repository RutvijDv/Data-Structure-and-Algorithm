#include <bits/stdc++.h>
using namespace std;

//Using O(n) extra space

int equilibriumPoint(long long a[], int n)
{

    long long prefix[n];
    prefix[0] = a[0];

    for (long long i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (prefix[i] - a[i] == prefix[n - 1] - prefix[i])
            return i + 1;
    }

    return -1;
}

//Using O(1) extra space

int equilibriumPoint(long long a[], int n)
{

    long long sum = 0;

    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int preSum = 0;
    for (int i = 0; i < n; i++)
    {

        sum = sum - a[i];

        if (sum == preSum)
            return i + 1;

        preSum += a[i];
    }

    return -1;
}