#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    sort(a.begin(), a.end());

    long long start = 0, end = m - 1;
    long long result = LONG_LONG_MAX;

    while (end < n)
    {
        result = min(a[end] - a[start], result);
        start++;
        end++;
    }

    return result;
}