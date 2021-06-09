#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<long long> &arr, int n, int k)
{
    // code here
    for (int i = 0; i < n; i += k)
    {
        if (i + k < n)
        {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }
        else
        {
            reverse(arr.begin() + i, arr.end());
        }
    }

    return;
}