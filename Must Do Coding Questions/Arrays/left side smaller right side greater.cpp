#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n)
{

    vector<int> L(n, 0), R(n, 0);

    L[0] = arr[0];
    for (int i = 1; i < n; i++)
        L[i] = max(arr[i], L[i - 1]);

    R[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        R[i] = min(arr[i], R[i + 1]);

    for (int i = 1; i < n - 1; i++)
    {
        if (L[i] == R[i])
            return L[i];
    }

    return -1;
}