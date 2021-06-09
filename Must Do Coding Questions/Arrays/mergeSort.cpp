#include <bits/stdc++.h>
using namespace std;

void merge(long long arr[], long long l, long long m, long long r)
{

    long long n1 = m - l + 1;
    long long n2 = r - m;

    long long L[n1], R[n2];

    for (long long i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long long i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
}

void mergeSort(long long arr[], long long l, long long r)
{
    if (l >= r)
        return;

    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);

    return;
}