#include <bits/stdc++.h>
using namespace std;

//Naive Solution

//use 2 for loops and check of every pair of element

//Efficient Solution

//Using merge Sort

void merge(long long arr[], long long l, long long m, long long r, long long &result)
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
            result += n1 - i;
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

long long mergeSort(long long arr[], long long l, long long r, long long &result)
{
    if (l >= r)
        return 0;

    long long m = l + (r - l) / 2;

    mergeSort(arr, l, m, result);
    mergeSort(arr, m + 1, r, result);
    merge(arr, l, m, r, result);

    return result;
}

long long int inversionCount(long long arr[], long long N)
{
    long long result = 0;
    mergeSort(arr, 0, N - 1, result);

    return result;
}